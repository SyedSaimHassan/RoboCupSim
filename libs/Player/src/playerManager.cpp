#include "playerManager.h"
namespace Player {
void PlayerManager::ManagePlayers(QPainter* p, QSet<int> PlayerKeys) {
  this->PlayerKeys = PlayerKeys;
  for (int RobotIndex = 1; RobotIndex <= int(cfg::SystemConfig::numRobots / 2); RobotIndex++) {
    movePlayer(RobotIndex);
  }
  InvKin.getVelocity();

  Render(p);
}

QPointF changeHelper(Eigen::Vector3d vector) { return QPointF(vector.x(), vector.y()); }

Eigen::Vector3d convertToEig(QPointF vector) { return Eigen::Vector3d(vector.x(), vector.y(), 0); }

void PlayerManager::deflectPlayers(int PlayerID1, int PlayerID2) {
  // avoiding overlap
  auto pos1 = getPose(PlayerID1);
  auto pos2 = getPose(PlayerID2);

  double distance = util::euclideanDistance(changeHelper(pos1), changeHelper(pos2));
  double deltaDis = cfg::SystemConfig::robotRadius * 2.005 - distance,
         deltaX = (pos2.x() - pos1.x()), deltaY = (pos2.y() - pos1.y());
  pos1.x() -= (deltaDis / 2) * deltaX / distance;
  pos2.x() += (deltaDis / 2) * deltaX / distance;
  pos1.y() -= (deltaDis / 2) * deltaY / distance;
  pos2.y() += (deltaDis / 2) * deltaY / distance;

  setPose(pos1, PlayerID1);
  setPose(pos2, PlayerID2);
  // avoiding overlap

  // deflection

  QPointF normal = (changeHelper(pos2) - changeHelper(pos1));
  distance = std::hypot(normal.x(), normal.y());
  normal /= distance;
  QPointF tangent(-normal.y(), normal.x());

  Eigen::Vector3d V1 = getPlayerV(PlayerID1), V2 = getPlayerV(PlayerID2);
  double Vref = (V2 - V1).dot(convertToEig(normal));

  double playerPlayerElasticiy = 0.5;

  double impulse = -cfg::SystemConfig::robotMass * (1 + playerPlayerElasticiy) * Vref / 2;

  Eigen::Vector3d j = convertToEig(impulse * normal);

  V1 -= j / cfg::SystemConfig::robotMass;
  V2 += j / cfg::SystemConfig::robotMass;

  SetPlayerV(V1, PlayerID1);
  SetPlayerV(V2, PlayerID2);
}
void PlayerManager::handleAuto(int PlayerInd) {
  (Trajectory.SetVelocityFromTraj(PlayerInd), PlayerInd);
}
void PlayerManager::handleManual(int PlayerInd) {
  if (PlayerInd != SelectedPlayer) return;

  float PlayerMaxAcc = cfg::SystemConfig::playerMaxAcceleration * dt;
  float PlayerRadianAcc = cfg::SystemConfig::playerMaxOmegaAcceleration * dt;
  Eigen::Vector3d PlayerPos = this->getPose(PlayerInd);
  Eigen::Vector3d PlayerVel = this->getPlayerV(PlayerInd);

  Eigen::Vector3d forwardTheta(cos(PlayerPos.z()), sin(PlayerPos.z()), 0);
  Eigen::Vector3d backwardTheta(cos(PlayerPos.z() + qDegreesToRadians(180.0)),
                                sin(PlayerPos.z() + qDegreesToRadians(180.0)), 0);
  Eigen::Vector3d rightTheta(cos(PlayerPos.z() + qDegreesToRadians(270.0)),
                             sin(PlayerPos.z() + qDegreesToRadians(270.0)), 0);
  Eigen::Vector3d leftTheta(cos(PlayerPos.z() + qDegreesToRadians(90.0)),
                            sin(PlayerPos.z() + qDegreesToRadians(90.0)), 0);

  for (int key : PlayerKeys) {
    switch (key) {
      case Qt::Key_W:
        PlayerVel += PlayerMaxAcc * forwardTheta;
        break;
      case Qt::Key_S:
        PlayerVel += PlayerMaxAcc * backwardTheta;
        break;
      case Qt::Key_D:
        PlayerVel += PlayerMaxAcc * rightTheta;
        break;
      case Qt::Key_A:
        PlayerVel += PlayerMaxAcc * leftTheta;
        break;
      case Qt::Key_C:
        PlayerVel += PlayerRadianAcc * (Eigen::Vector3d(0, 0, 1));
        break;
      case Qt::Key_X:
        PlayerVel -= PlayerRadianAcc * (Eigen::Vector3d(0, 0, 1));
        break;
      case Qt::Key_M:
        PlayerVel = Eigen::Vector3d(0, 0, 0);
        break;
    }
  }

  SetPlayerV(PlayerVel, PlayerInd);
}
void PlayerManager::movePlayer(int playerID = 0) {
  auto applyDecel = [](float vel, float maxAccel) {
    float decel = std::min(std::abs(vel), maxAccel);
    if (vel > 0) decel *= -1;
    return vel + decel;
  };

  cfg::SystemConfig::teamOnePlayerVel[playerID - 1].x() =
      applyDecel(cfg::SystemConfig::teamOnePlayerVel[playerID - 1].x(),
                 cfg::SystemConfig::playerMaxAcceleration);
  cfg::SystemConfig::teamOnePlayerVel[playerID - 1].y() =
      applyDecel(cfg::SystemConfig::teamOnePlayerVel[playerID - 1].y(),
                 cfg::SystemConfig::playerMaxAcceleration);
  cfg::SystemConfig::teamOnePlayerVel[playerID - 1].z() =
      applyDecel(cfg::SystemConfig::teamOnePlayerVel[playerID - 1].z(),
                 cfg::SystemConfig::playerMaxOmegaAcceleration);

  switch (cfg::SystemConfig::PlayerStates[playerID - 1]) {
    case cfg::SystemConfig::RobotState::Autonomous:
      handleAuto(playerID);
      break;
    case cfg::SystemConfig::RobotState::Manual:
      handleManual(playerID);
      break;
    default:
      break;
  }

  cfg::SystemConfig::teamOnePlayerPos[playerID - 1].x() =
      (cfg::SystemConfig::teamOnePlayerPos[playerID - 1].x() +
       cfg::SystemConfig::teamOnePlayerVel[playerID - 1].x());
  cfg::SystemConfig::teamOnePlayerPos[playerID - 1].y() =
      (cfg::SystemConfig::teamOnePlayerPos[playerID - 1].y() +
       cfg::SystemConfig::teamOnePlayerVel[playerID - 1].y());
  cfg::SystemConfig::teamOnePlayerPos[playerID - 1].z() =
      (std::fmod(cfg::SystemConfig::teamOnePlayerPos[playerID - 1].z() +
                     cfg::SystemConfig::teamOnePlayerVel[playerID - 1].z(),
                 (2.0f * M_PI)));

  // detecting collision
  for (int RobotIndex2 = playerID + 1; RobotIndex2 <= int(cfg::SystemConfig::numRobots / 2);
       RobotIndex2++) {
    Eigen::Vector3d pos1 = Players::getPose(playerID);
    Eigen::Vector3d pos2 = Players::getPose(RobotIndex2);
    if (util::euclideanDistanceVector(cfg::SystemConfig::teamOnePlayerPos[playerID - 1],
                                      cfg::SystemConfig::teamOnePlayerPos[RobotIndex2 - 1]) <=
        2.005 * cfg::SystemConfig::robotRadius) {
      deflectPlayers(playerID, RobotIndex2);
    }
  }

  // -------------x-------------x----------//
}

void PlayerManager::handleBall(int PlayerID){
  using cfg::SystemConfig;


  Eigen::Vector3d pose3 = getPose(PlayerID);
  Eigen::Vector2d playerPos(pose3.x(), pose3.y());
  Eigen::Vector3d playerVel3 = getPlayerV(PlayerID);
  Eigen::Vector2d playerVel(playerVel3.x(), playerVel3.y());

  Eigen::Vector2d ballPos = SystemConfig::currBallPosition;
  Eigen::Vector2d ballVel = SystemConfig::currBallVel;

  Eigen::Vector2d forward(std::cos(pose3.z()), std::sin(pose3.z()));

  Eigen::Vector2d toBall = ballPos - playerPos;
  double dist = toBall.norm();

  double pickupDist = SystemConfig::robotRadius + SystemConfig::ballRadius + 0.05;

  if (SystemConfig::ballHeld && SystemConfig::ballHolder == PlayerID) {
    if (PlayerKeys.contains(Qt::Key_Space)) {
      SystemConfig::ballHeld = false;
      SystemConfig::ballHolder = -1;
      double throwSpeed = SystemConfig::ballAcceleration * 5.0; 
      SystemConfig::currBallVel = playerVel + forward * throwSpeed;
      SystemConfig::currBallPosition = playerPos + forward * (SystemConfig::robotRadius + SystemConfig::ballRadius + 0.01);
    } else {
      SystemConfig::currBallPosition = playerPos + forward * (SystemConfig::robotRadius + SystemConfig::ballRadius + 0.01);
      SystemConfig::currBallVel = playerVel; 
    }
    return;
  }

  if (!SystemConfig::ballHeld) {
    double forwardDot = toBall.dot(forward);
    if (forwardDot > 0 && dist <= pickupDist) {
      SystemConfig::ballHeld = true;
      SystemConfig::ballHolder = PlayerID;
      SystemConfig::currBallPosition = playerPos + forward * (SystemConfig::robotRadius + SystemConfig::ballRadius + 0.01);
      SystemConfig::currBallVel = playerVel;
    }
  }
}

Eigen::Vector3d PlayerManager::getPlayerV(int PlayerID) {
  return cfg::SystemConfig::teamOnePlayerVel[PlayerID - 1];
}
void PlayerManager::SetPlayerV(Eigen::Vector3d PlayerV, int PlayerID) {
  float playerMax = cfg::SystemConfig::playerMaxSpeed;
  float playerMin = -cfg::SystemConfig::playerMaxSpeed;
  float rotationMax = cfg::SystemConfig::playerMaxRotation;
  float rotationMin = -cfg::SystemConfig::playerMaxRotation;
  PlayerV = Eigen::Vector3d(std::clamp(float(PlayerV.x()), playerMin, playerMax),
                            std::clamp(float(PlayerV.y()), playerMin, playerMax),
                            std::clamp(float(PlayerV.z()), rotationMin, rotationMax));
  if (std::abs(cfg::SystemConfig::teamOnePlayerPos[PlayerID - 1].y()) -
          (cfg::SystemConfig::robotRadius) >=
      (cfg::Dimensions::outerFieldHeight / 2)) {
    if ((std::abs(cfg::SystemConfig::teamOnePlayerPos[PlayerID - 1].y()) ==
             cfg::SystemConfig::teamOnePlayerPos[PlayerID - 1].y() and
         abs(PlayerV.y()) == PlayerV.y()) or
        (std::abs(cfg::SystemConfig::teamOnePlayerPos[PlayerID - 1].y()) !=
             cfg::SystemConfig::teamOnePlayerPos[PlayerID - 1].y() and
         abs(PlayerV.y()) != PlayerV.y())) {
      PlayerV = Eigen::Vector3d(PlayerV.x(), 0, PlayerV.z());
    }
  }
  if (std::abs(cfg::SystemConfig::teamOnePlayerPos[PlayerID - 1].x()) -
          (cfg::SystemConfig::robotRadius) >=
      (cfg::Dimensions::outerFieldWidth / 2)) {
    if ((std::abs(cfg::SystemConfig::teamOnePlayerPos[PlayerID - 1].x()) ==
             cfg::SystemConfig::teamOnePlayerPos[PlayerID - 1].x() and
         abs(PlayerV.x()) == PlayerV.x()) or
        (std::abs(cfg::SystemConfig::teamOnePlayerPos[PlayerID - 1].x()) !=
             cfg::SystemConfig::teamOnePlayerPos[PlayerID - 1].x() and
         abs(PlayerV.x()) != PlayerV.x())) {
      PlayerV = Eigen::Vector3d(0, PlayerV.y(), PlayerV.z());
    }
  }

  cfg::SystemConfig::teamOnePlayerVel[PlayerID - 1] = PlayerV;
}
}  // namespace Player
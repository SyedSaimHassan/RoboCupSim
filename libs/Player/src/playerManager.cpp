#include "playerManager.h"
namespace Player {
void PlayerManager::ManagePlayers(QPainter *p,QSet<int> Keys) {
  for (int RobotIndex = 1; RobotIndex < int(cfg::SystemConfig::numRobots / 2); RobotIndex++) {
    movePlayer(RobotIndex);
  }
  Render(p);
}

void PlayerManager::detectCollision() {
  // for (int RobotIndex1 = 1; RobotIndex1 <= int(cfg::SystemConfig::numRobots / 2); RobotIndex1++)
  // {
  //   for (int RobotIndex2 = RobotIndex1 + 1; RobotIndex2 <= int(cfg::SystemConfig::numRobots /
  //   2);
  //        RobotIndex2++) {
  //     Eigen::Vector3d pos1 = Players::getPose(RobotIndex1);
  //     Eigen::Vector3d pos2 = Players::getPose(RobotIndex2);
  //     if (util::withinRadius(playerPositions[RobotIndex1 - 1], playerPositions[RobotIndex2 -
  //     1])) {
  //       deflectPlayers(RobotIndex1, RobotIndex2);
  //       std::cout << RobotIndex1 << ' ' << RobotIndex2 << ' '
  //                 << util::euclideanDistance(QPointF(pos1.x(), pos1.y()),
  //                                            QPointF(pos2.x(), pos2.y()))
  //                 << std::endl;
  //     }
  //   }
  // }
  // Eigen::Vector3d pos1 = Players::getPose(2);
  // Eigen::Vector3d pos2 = Players::getPose(1);
  // std::cout << pos1.x() << ' ' << pos1.y() << ' ' << pos2.x() << ' ' << pos2.y() << std::endl;
  // std::cout << util::euclideanDistance(QPointF(pos1.x(), pos1.y()), QPointF(pos2.x(), pos2.y()))
  //           << std::endl;
}

QPointF changeHelper(Eigen::Vector3d vector) { return QPointF(vector.x(), vector.y()); }

void PlayerManager::deflectPlayers(int PlayerID1, int PlayerID2) {

  //avoiding overlap
  auto pos1 = getPose(PlayerID1);
  auto pos2 = getPose(PlayerID2);

  double distance = util::euclideanDistance(changeHelper(pos1), changeHelper(pos2));
  double deltaDis = cfg::SystemConfig::robotRadius * 2 - distance,
         deltaX = std::abs(pos1.x() - pos2.x()), deltaY = std::abs(pos1.y() - pos2.y());
  if (pos1.x() > pos2.x()) std::swap(pos1, pos2), std::swap(PlayerID1, PlayerID2);

  pos1.x() -= (deltaDis / 2) * deltaX / distance;
  pos2.x() += (deltaDis / 2) * deltaX / distance;
  if (pos1.y() > pos2.y()) std::swap(pos1, pos2), std::swap(PlayerID1, PlayerID2);
  pos1.y() -= (deltaDis / 2) * deltaY / distance;
  pos2.y() += (deltaDis / 2) * deltaY / distance;

  setPose(pos1, PlayerID1);
  setPose(pos2, PlayerID2);
  //avoiding overlap

  //deflection
  

}
void PlayerManager::handleAuto(int PlayerInd) {}
void PlayerManager::handleManual(int PlayerInd) {}
void PlayerManager::movePlayer(int playerID = 0) {
  // detecting collision
  for (int RobotIndex1 = 1; RobotIndex1 <= int(cfg::SystemConfig::numRobots / 2); RobotIndex1++) {
    for (int RobotIndex2 = RobotIndex1 + 1; RobotIndex2 <= int(cfg::SystemConfig::numRobots / 2);
         RobotIndex2++) {
      Eigen::Vector3d pos1 = Players::getPose(RobotIndex1);
      Eigen::Vector3d pos2 = Players::getPose(RobotIndex2);
      if (util::euclideanDistance(playerPositions[RobotIndex1 - 1],
                                  playerPositions[RobotIndex2 - 1]) <= 0.408) {
        deflectPlayers(RobotIndex1, RobotIndex2);
      }
    }
  }
  // -------------x-------------x----------//

  playerPositions[playerID - 1].setX(playerPositions[playerID - 1].x() +
                                     playerVelocities[playerID - 1].x());
  playerPositions[playerID - 1].setY(playerPositions[playerID - 1].y() +
                                     playerVelocities[playerID - 1].y());
  playerGyroAngle[playerID - 1] =
      playerGyroAngle[playerID - 1] + playerVelocities[playerID - 1].z();
  // Decel for x
  float playerXDec = std::min(std::abs(float(playerVelocities[playerID - 1].x())),
                              cfg::SystemConfig::playerMaxAcceleration);
  if (playerVelocities[playerID - 1].x() > 0) {
    playerXDec *= -1;
  }
  playerVelocities[playerID - 1].x() += playerXDec;
  // End decel

  float playerYDec = std::min(std::abs(float(playerVelocities[playerID - 1].y())),
                              cfg::SystemConfig::playerMaxAcceleration);
  if (playerVelocities[playerID - 1].y() > 0) {
    playerYDec *= -1;
  }
  playerVelocities[playerID - 1].y() += playerYDec;

  float playerZDec = std::min(std::abs(float(playerVelocities[playerID - 1].z())),
                              cfg::SystemConfig::playerMaxOmegaAcceleration);
  if (playerVelocities[playerID - 1].z() > 0) {
    playerZDec *= -1;
  }
  playerVelocities[playerID - 1].z() += playerZDec;
}

Eigen::Vector3d PlayerManager::getPlayerV(int PlayerID) { return playerVelocities[PlayerID - 1]; }
void PlayerManager::SetPlayerV(Eigen::Vector3d PlayerV, int PlayerID) {
  float playerMax = cfg::SystemConfig::playerMaxSpeed;
  float playerMin = -cfg::SystemConfig::playerMaxSpeed;
  float rotationMax = cfg::SystemConfig::playerMaxRotation;
  float rotationMin = -cfg::SystemConfig::playerMaxRotation;
  PlayerV = Eigen::Vector3d(std::clamp(float(PlayerV.x()), playerMin, playerMax),
                            std::clamp(float(PlayerV.y()), playerMin, playerMax),
                            std::clamp(float(PlayerV.z()), rotationMin, rotationMax));
  playerVelocities[PlayerID - 1] = PlayerV;
}
}  // namespace Player
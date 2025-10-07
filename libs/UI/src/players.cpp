#include <players.h>
#include <iostream>
void Players::Render(QPainter *painter) {
  painter->setBrush(Qt::blue);
  painter->setPen(QPen(Qt::black, 0.05));
  for (int i = 1; i <= int(cfg::SystemConfig::numRobots / 2); i++) {
    movePlayer(i);
    painter->save();
    QPointF pos = playerPositions[i - 1];
    painter->translate(pos);
    painter->rotate(playerGyroAngle[i - 1]);

    Players::drawPlayers(painter, i);
    painter->restore();
  }
}

void Players::drawPlayers(QPainter *painter, int playerNumber) {
  painter->drawEllipse(QPointF(0, 0), cfg::SystemConfig::robotRadius,
                       cfg::SystemConfig::robotRadius);
  QPointF start = QPointF(0, 0);
  qreal r = cfg::SystemConfig::robotRadius;
  qreal angle = playerGyroAngle[playerNumber - 1];

  QPointF end(start.x() + r * cos(angle), start.y() + r * sin(angle));

  painter->drawLine(start, end);
}

void Players::setPose(Eigen::Vector3d pose, int playerID = 0) {
  if (!playerID) {
    return;
  }

  playerPositions[playerID - 1].setX(pose.x());
  playerPositions[playerID - 1].setY(pose.y());
  playerGyroAngle[playerID - 1] = pose.z();
}

Eigen::Vector3d Players::getPose(int playerID) {
  return Eigen::Vector3d(playerPositions[playerID - 1].x(), playerPositions[playerID - 1].y(),
                         playerGyroAngle[playerID - 1]);
}
void Players::movePlayer(int playerID = 0) {
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

  playerVelocities[playerID - 1].y() += playerYDec;
    float playerZDec = std::min(std::abs(float(playerVelocities[playerID - 1].z())),
                              cfg::SystemConfig::playerMaxOmegaAcceleration);
  if (playerVelocities[playerID - 1].z() > 0) {
    playerZDec *= -1;
  }
  playerVelocities[playerID - 1].z() += playerZDec;
}

Eigen::Vector3d Players::getPlayerV(int PlayerID) { return playerVelocities[PlayerID - 1]; }
void Players::SetPlayerV(Eigen::Vector3d PlayerV, int PlayerID) {
  float playerMax = cfg::SystemConfig::playerMaxSpeed;
  float playerMin = -cfg::SystemConfig::playerMaxSpeed;
  float rotationMax = cfg::SystemConfig::playerMaxRotation;
  float rotationMin = -cfg::SystemConfig::playerMaxRotation;
  PlayerV = Eigen::Vector3d(std::clamp(float(PlayerV.x()), playerMin, playerMax),
                            std::clamp(float(PlayerV.y()), playerMin, playerMax),
                            std::clamp(float(PlayerV.z()), rotationMin, rotationMax));
  playerVelocities[PlayerID - 1] = PlayerV;
}
#include "playerManager.h"
namespace Player {
void PlayerManager::ManagePlayers(QPainter *p) {
  for (int RobotIndex = 1; RobotIndex < int(cfg::SystemConfig::numRobots / 2); RobotIndex++) {
    movePlayer(RobotIndex);
  }
  Render(p);
}
void PlayerManager::movePlayer(int playerID = 0) {
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
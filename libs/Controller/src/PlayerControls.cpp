#include "Game.h"

namespace Controller {
void Game::handlePlayer() {
  float PlayerCosX = cos(1);
  float PlayerSinY = sin(1);
  float PlayerMaxAcc = cfg::SystemConfig::playerMaxAcceleration * dt;
  float PlayerRadianAcc = cfg::SystemConfig::playerMaxOmegaAcceleration * dt;
  for (int key : PlayerKeys) {
    switch (key) {
        // Selecting Player
      case Qt::Key_0:
        SelectedPlayerId = 0;
        break;
      case Qt::Key_1:
        SelectedPlayerId = 1;
        break;
      case Qt::Key_2:
        SelectedPlayerId = 2;
        break;
      case Qt::Key_3:
        SelectedPlayerId = 3;
        break;
      case Qt::Key_4:
        SelectedPlayerId = 4;
        break;
        // End of player Selection
    }
  }

  Eigen::Vector3d PlayerPos = this->Players_.getPose(SelectedPlayerId);
  Eigen::Vector3d PlayerVel = this->Players_.getPlayerV(SelectedPlayerId);

  Eigen::Vector3d forwardTheta(cos(PlayerPos.z()), sin(PlayerPos.z()), 0);
  Eigen::Vector3d backwardTheta(cos(PlayerPos.z() + qDegreesToRadians(180.0)),
                                sin(PlayerPos.z() + qDegreesToRadians(180.0)), 0);
  Eigen::Vector3d rightTheta(cos(PlayerPos.z() + qDegreesToRadians(270.0)),
                             sin(PlayerPos.z() + qDegreesToRadians(270.0)), 0);
  Eigen::Vector3d leftTheta(cos(PlayerPos.z() + qDegreesToRadians(90.0)),
                            sin(PlayerPos.z() + qDegreesToRadians(90.0f)), 0);

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

  ;
  this->Players_.SetPlayerV(PlayerVel, SelectedPlayerId);
}

}  // namespace Controller
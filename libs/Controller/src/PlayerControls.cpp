#include "Game.h"

namespace Controller {

void Game::handlePlayer() {
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
  this->Players_.SelectedPlayer = SelectedPlayerId;
  for (int key : PlayerKeys) {
    switch (key) {
      case Qt::Key_K:
        cfg::SystemConfig::PlayerStates[SelectedPlayerId - 1] =
            cfg::SystemConfig::RobotState::Manual;
        break;
      case Qt::Key_L:
        cfg::SystemConfig::PlayerStates[SelectedPlayerId - 1] =
            cfg::SystemConfig::RobotState::Autonomous;
        break;
    }
  }
}

}  // namespace Controller
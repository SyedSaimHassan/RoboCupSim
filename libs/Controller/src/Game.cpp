#include "Game.h"

namespace Controller {

Game::Game(QWidget *parent) : QWidget(parent) {
  std::cout << "[Controller::Game::Game] Startup Successfull" << std::endl;
  this->resize(QGuiApplication::primaryScreen()->geometry().size());
  QTimer *timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, [this]() { this->update(); });
  timer->start(16);
}

void Game::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  cfg::Dimensions::screenWidth = width();
  cfg::Dimensions::screenHeight = height();
  Transformation::instance().transformation(&painter, rect());
  keyControls();
  drawField(&painter);
  drawPlayers(&painter);
  drawBall(&painter);
}

void Game::drawField(QPainter *painter) { this->Field.CreateField(painter); }
void Game::drawPlayers(QPainter *painter) { this->Players_.Render(painter); }
void Game::drawBall(QPainter *painter) { this->Ball_.drawBall(painter); }

void Game::keyPressEvent(QKeyEvent *event) { handleInsertKey(event->key()); }
void Game::keyReleaseEvent(QKeyEvent *event) { handleRemoveKey(event->key()); }
void Game::keyControls() {
  Eigen::Vector3d PlayerSpeed(0, 0, 0);
  for (int key : PlayerKeys) {
    switch (key) {
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

      case Qt::Key_W:
        PlayerSpeed.y() = cfg::SystemConfig::playerMaxSpeed / 60;
        break;
      case Qt::Key_S:
        PlayerSpeed.y() = -cfg::SystemConfig::playerMaxSpeed / 60;
        break;
      case Qt::Key_D:
        PlayerSpeed.x() = cfg::SystemConfig::playerMaxSpeed / 60;
        break;
      case Qt::Key_A:
        PlayerSpeed.x() = -cfg::SystemConfig::playerMaxSpeed / 60;
        break;
      case Qt::Key_C:
        PlayerSpeed.z() = cfg::SystemConfig::playerMaxRotation / 60;
        break;
      case Qt::Key_X:
        PlayerSpeed.z() = -cfg::SystemConfig::playerMaxRotation / 60;
        break;
      // Debugging
      case Qt::Key_Up:
        Ball_.DebugMove(0.0f, 1.0f * Div);
        break;
      case Qt::Key_Down:
        Ball_.DebugMove(0.0f, -1.0f * Div);

        break;
      case Qt::Key_Left:
        Ball_.DebugMove(-1.0f * Div, 0.0f);

        break;
      case Qt::Key_Right:
        Ball_.DebugMove(1.0f * Div, 0.0f);
        break;

      case Qt::Key_Slash:
        Ball_.DebugMove(0.0f, 0.0f);
        break;
    }
  }
  this->Players_.setPose((this->Players_.getPose(SelectedPlayerId) + PlayerSpeed),
                         SelectedPlayerId);
}
void Game::handleInsertKey(int key) { PlayerKeys.insert(key); }
void Game::handleRemoveKey(int key) { PlayerKeys.remove(key); }

}  // namespace Controller

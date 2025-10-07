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
  ManagePlayers(&painter);
  drawBall(&painter);
}

void Game::drawField(QPainter *painter) { this->Field.CreateField(painter); }
void Game::ManagePlayers(QPainter *painter) { this->Players_.ManagePlayers(painter); }
void Game::drawBall(QPainter *painter) { this->Ball_.drawBall(painter); }

void Game::keyPressEvent(QKeyEvent *event) { handleInsertKey(event->key()); }
void Game::keyReleaseEvent(QKeyEvent *event) { handleRemoveKey(event->key()); }
void Game::keyControls() {
  handlePlayer();
}
void Game::handleInsertKey(int key) { PlayerKeys.insert(key); }
void Game::handleRemoveKey(int key) { PlayerKeys.remove(key); }

}  // namespace Controller

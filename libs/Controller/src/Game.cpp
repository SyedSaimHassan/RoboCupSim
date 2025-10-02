#include "Game.h"

namespace Controller {

Game::Game(QWidget *parent = nullptr) : QWidget(parent) {
  std::cout << "[Controller::Game::Game] Startup Successfull" << std::endl;
  this->resize(QGuiApplication::primaryScreen()->geometry().size());
}

void Game::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  cfg::Dimensions::screenWidth = width();
  cfg::Dimensions::screenHeight = height();
  drawField(&painter);
  drawPlayers(&painter);
  drawBall(&painter);
}

void Game::drawField(QPainter *painter) {}
void Game::drawPlayers(QPainter *painter) {
  
}
void Game::drawBall(QPainter *painter) {}

}  // namespace Controller

#include "ball.h"

namespace Ball {
void Ball::drawBall(QPainter* painter) {
  moveBall();
  painter->setBrush(QBrush(Qt::red));
  painter->setPen(QPen(Qt::black, 0.01));
  qreal X = ballPos.x();
  qreal Y = ballPos.y();
  QPointF Cords(X, Y);
  painter->drawEllipse(Cords, ballDia, ballDia);
}
void Ball::checkOutOfMap() {
  if (ballPos.x() + cfg::SystemConfig::ballRadius * 2 > cfg::Dimensions::fieldWidth / 2) {
    ballPos.x() = (cfg::Dimensions::fieldWidth / 2) - (cfg::SystemConfig::ballRadius * 2);
  } else if (ballPos.x() < -cfg::Dimensions::fieldWidth / 2) {
    ballPos.x() = (-cfg::Dimensions::fieldWidth / 2);
  };
  if (ballPos.y() + cfg::SystemConfig::ballRadius * 2 > cfg::Dimensions::fieldHeight / 2) {
    ballPos.y() = (cfg::Dimensions::fieldHeight / 2) - (cfg::SystemConfig::ballRadius * 2);
  } else if (ballPos.y() < -cfg::Dimensions::fieldHeight / 2) {
    ballPos.y() = (-cfg::Dimensions::fieldWidth / 2);
  }
}
void Ball::moveBall() {
  ballPos += ballV;
  checkOutOfMap();
}
void Ball::DebugMove(float x, float y) {
  if (x == 0 and y == 0) {
    ballV.x() = 0;
    ballV.y() = 0;
    return;
  }
  // std::cout << x << " " << y << std::endl;
  ballV.x() += x;
  ballV.y() += y;
  std::cout << ballV.x() << " " << ballV.y() << std::endl;
}
}  // namespace Ball
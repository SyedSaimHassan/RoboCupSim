#include "ball.h"

void Ball::drawBall(QPainter* painter) {
  painter->setBrush(QBrush(Qt::red));
  if (ballPos.y() < 0 or ballPos.y() + ballDia > cfg::Dimensions::screenHeight) ballV.y() *= -1;
  if (ballPos.x() + ballDia > cfg::Dimensions::screenWidth or ballPos.x() < 0) ballV.x() *= -1;
  if (respawnBall) ballPos = initPos, ballV = Eigen::Vector2d(0, 0);
  painter->drawEllipse(ballPos.x(), ballPos.y(), ballDia, ballDia);
}

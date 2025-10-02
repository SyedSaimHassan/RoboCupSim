#ifndef BALL_H
#define BALL_H

#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QTimer>
#include <QKeyEvent>
#include <cmath>
#include <iostream>
#include "systemConfig.h"
#include "dimensions.h"
namespace Ball {
class Ball : public QWidget {
 public:
  void drawBall(QPainter *painter);
  void checkOutOfMap();
  void moveBall();
  qreal ballDia = cfg::SystemConfig::ballRadius * 2;

  Eigen::Vector2d ballV = Eigen::Vector2d(0.0f, 0.0f);

  Eigen::Vector2d ballPos = Eigen::Vector2d(cfg::SystemConfig::initBallPosition);
  Eigen::Vector2d getBallV() { return ballV; }
  Eigen::Vector2d getBallPos() { return ballPos; }
  void DebugMove(float x, float y);
  bool respawnBall = 0;
};
}  // namespace Ball
#endif
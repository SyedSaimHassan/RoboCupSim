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
#include "transformation.h"
#include "systemConfig.h"

class Ball : public QWidget {
 public:
  void drawBall(QPainter *painter);

  qreal ballDia = cfg::SystemConfig::ballRadius;
  Eigen::Vector2d ballV = Eigen::Vector2d(0, 0), ballPos = cfg::SystemConfig::initBallPosition,
                  initPos = ballPos;
  Eigen::Vector2d getBallV() { return ballV; }
  Eigen::Vector2d getBallPos() { return ballPos; }

  bool respawnBall = 0;
};
#endif
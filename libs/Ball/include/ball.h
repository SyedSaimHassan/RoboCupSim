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
  Ball(QWidget *parent = nullptr) : QWidget(parent) {}

 protected:
  virtual void drawBall(QPainter *painter);

  qreal ballDia = cfg::SystemConfig::ballRadius;
  Eigen::Vector2d ballV = Eigen::Vector2d(0, 0), ballPos = cfg::SystemConfig::initBallPosition,
                  initPos = ballPos;

  bool respawnBall = 0;
};
#endif
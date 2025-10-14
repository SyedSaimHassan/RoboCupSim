#ifndef COLLISIONS_H
#define COLLISIONS_H
// C++ Libraries
#include <cmath>
#include <vector>
#include <string>
#include <Eigen/Dense>
#include <iostream>

// Qt Libraries
#include <QWidget>
#include <QPainter>
#include <QPointF>
#include <QTimer>
#include <QtMath>
#include <QKeyEvent>
#include <QDebug>

// Self made libraries
#include "players.h"
#include "playerManager.h"
#include "systemConfig.h"

class Collision : public Player::PlayerManager {
 public:
  void detectCollision();
  void deflectPlayers(int PlayerID1, int PlayerID2);
  void deflectBall(int PlayerID);
};

#endif
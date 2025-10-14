#ifndef PLAYER_MANAGER_H
#define PLAYER_MANAGER_H
// C++ Libraries
#include <cmath>
#include <vector>
#include <string>
#include <Eigen/Dense>

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
#include "systemConfig.h"
#include "Collision.h"
// #define framerate 60
namespace Player {

class PlayerManager : public Players{
 private:
  std::vector<Eigen::Vector3d> playerVelocities = {
      Eigen::Vector3d(0, 0, 0), Eigen::Vector3d(0, 0, 0), Eigen::Vector3d(0, 0, 0),
      Eigen::Vector3d(0, 0, 0)};
      public:
    std::vector<Eigen::Vector3d> HelperConvert(std::vector<QPointF> Position,std::vector<double> Gyro);
  void ManagePlayers(QPainter *p);
  void movePlayer(int playerID);
  Eigen::Vector3d getPlayerV(int PlayerID);
  void SetPlayerV(Eigen::Vector3d PlayerV, int PlayerID);
  void decelPlayer(int PlayerID);
  Physics::Collision Collisions;
};

}  // namespace Player

#endif
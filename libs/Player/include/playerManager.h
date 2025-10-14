#ifndef PLAYER_MANAGER_H
#define PLAYER_MANAGER_H
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
#include "systemConfig.h"
#define dt 1 / cfg::SystemConfig::frameRate
namespace Player {

class PlayerManager : public Players {
 private:
  std::vector<Eigen::Vector3d> playerVelocities = {
      Eigen::Vector3d(0, 0, 0), Eigen::Vector3d(0, 0, 0), Eigen::Vector3d(0, 0, 0),
      Eigen::Vector3d(0, 0, 0)};
  QSet<int> PlayerKeys;

 public:
  void detectCollision();
  void deflectPlayers(int PlayerID1, int PlayerID2);
  void deflectBall(int PlayerID);

  int SelectedPlayer = 0;
  void handleAuto(int PlayerInd);
  void handleManual(int PlayerInd);
  void ManagePlayers(QPainter *p, QSet<int> Keys);
  void movePlayer(int playerID);
  Eigen::Vector3d getPlayerV(int PlayerID);
  void SetPlayerV(Eigen::Vector3d PlayerV, int PlayerID);
};

}  // namespace Player

#endif
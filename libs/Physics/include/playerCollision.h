#ifndef PLAYER_COLLISIONS_H
#define PLAYER_COLLISIONS_H
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

namespace Physics{

    void checkPlayerCollisions(std::vector<Eigen::Vector3d>playerPositions,std::vector<Eigen::Vector3d>PlayerVelocities);
    void deflectPlayers(std::vector<Eigen::Vector3d>PlayerPositions,std::vector<Eigen::Vector3d>PlayerVelocities,int PlayerId1,int PlayerId2);
}
#endif
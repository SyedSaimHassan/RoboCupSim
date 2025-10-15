#ifndef COLLISIONS_H
#define COLLISIONS_H
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
    std::vector<std::pair<int,int>>Do(std::vector<Eigen::Vector3d>PlayerPositions);
    std::bool checkCollision(Eigen::Vector3d PlayerID1,Eigen::Vector3d PlayerID2);
}
#endif
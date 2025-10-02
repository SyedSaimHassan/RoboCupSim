#ifndef PLAYER_H
#define PLAYER_H
//C++ Libraries
#include <cmath>
#include <vector>
#include <string>
#include <Eigen/Dense>

//Qt Libraries
#include <QWidget>
#include <QPainter>
#include <QPointF>
#include <QTimer>
#include <QtMath>
#include <QKeyEvent>
#include <QDebug>

//Self made libraries
#include "playerUtil.h"
#include "systemConfig.h"

class Players : public QWidget{
    public:

        //Body Parameters
        std::vector<QPointF> playerPositions = {QPointF(cfg::SystemConfig::teamOneStartFormation[0][0],cfg::SystemConfig::teamOneStartFormation[0][1]),
            QPointF(cfg::SystemConfig::teamOneStartFormation[1][0],cfg::SystemConfig::teamOneStartFormation[1][1]),
            QPointF(cfg::SystemConfig::teamOneStartFormation[2][0],cfg::SystemConfig::teamOneStartFormation[2][1]),
            QPointF(cfg::SystemConfig::teamOneStartFormation[3][0],cfg::SystemConfig::teamOneStartFormation[3][1])};
        std::vector<double> playerGyroAngle = {0.0,0.0,0.0,0.0};
  
    //Render
    void Render(QPainter *painter);
    void drawPlayers(QPainter *painter,int playerNumber);
    Eigen::Vector3d getPose(int playerID);
    void setPose(Eigen::Vector3d pose, int playerID);

    //Movement Functions (work later)
    // void keyPressEvent(QKeyEvent *event) override;
    // and other such functions

};

#endif

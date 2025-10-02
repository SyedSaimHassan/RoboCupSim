#pragma once
//C++ Libraries
#include <cmath>
#include <vector>
#include <string>

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

class Players : public QWidget{
    public:
        //Physics Parameters
        QPointF playerMaxSpeed;
        QPointF playerMaxAcceleration;
        QPointF playerMaxShootForce;

        //Body Parameters
        std::vector<QPointF> playerPositions = {QPointF(0,0),QPointF(2,2),QPointF(50,50),QPointF(80,80)};
        std::vector<double> playerGyroAngle = {0.0,0.0,0.0,0.0};
  
    //Render
    void Render(QPainter *painter);
    void drawPlayers(QPainter *painter,int playerNumber);
    //Movement Functions (work later)
    // void keyPressEvent(QKeyEvent *event) override;
    // and other such functions

};
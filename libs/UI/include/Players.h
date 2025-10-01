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

class Players{
    private:
        //Physics Parameters
        QPointF playerMaxSpeed;
        QPointF playerMaxAcceleration;
        QPointF playerMaxShootForce;

        //Body Parameters
        std::vector<QPointF> playerPositions;
        std::vector<double> playerGyroAngle = {0.0,0.0,0.0,0.0};
  
    //Render
    void Render(QPainter *painter);
    void drawPlayers(QPainter *painter, int playerNumber);


    //Movement Functions (work later)
    // void keyPressEvent(QKeyEvent *event) override;
    // and other such functions

};
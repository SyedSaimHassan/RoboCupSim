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
        double playerMaxSpeed;
        double playerMaxAcceleration;
        double playerMaxShootForce;

        //Body Parameters
        QPointF playerPosition;
        double playerGyroAngle = 0.0;
  
    //Render
    void Render(QPainter *painter);
    void drawPlayers(QPainter *painter);
    void rotate(QPainter *painter);


    //Movement Functions (work later)
    // void keyPressEvent(QKeyEvent *event) override;
    // and other such functions

};
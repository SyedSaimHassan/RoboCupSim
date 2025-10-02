#ifndef GENERAGE_UI_H
#define GENERATE_UI_H
#include<iostream>
#include<QWidget>
#include<QPainter>
#include<QPaintEvent>
#include<QPen>
#include<QBrush>
#include<vector>
#include<QTimer>
#include<iostream>
#include<QApplication>
#include<QKeyEvent>
#include<QRandomGenerator>
// #include"Dimensions.h"
// #include "Transformation.h"

class UI:public QWidget{

    public:
        void CreateField(QPainter *painter);
    protected:
        void paintEvent(QPaintEvent *) override;
};

#endif
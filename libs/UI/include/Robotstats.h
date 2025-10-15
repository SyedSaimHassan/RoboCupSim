#ifndef ROBOTSTATS_H
#define ROBOTSTATS_H
#include<QPainter>
#include<QWidget>
#include<QPen>
#include<QBrush>
#include "dimensions.h"
#include "systemConfig.h"
class RbSt:public QWidget{
    public:
        int PLayerID=0;
        void drawStats(QPainter *painter);
};

#endif
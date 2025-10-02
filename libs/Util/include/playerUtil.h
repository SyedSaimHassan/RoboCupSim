#ifndef PLAYERUTIL_H
#define PLAYERUTIL_H
//CPP libraries
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

//QT5 libraries
#include <QPointF>


namespace util{

double wrapAngle(double angle);
double euclideanDistance(QPointF p1,QPointF p2);
bool withinRadius(QPointF p1, QPointF p2);


}

#endif
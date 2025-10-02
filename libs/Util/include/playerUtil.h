#pragma once

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
bool withinRadius(double p1, double p2);


}

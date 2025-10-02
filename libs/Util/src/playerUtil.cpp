#include "playerUtil.h"

namespace util{

double wrapAngle(double angle){
    angle = std::fmod(angle, 2.0 * M_PI);
    if (angle < 0)
        angle += 2.0 * M_PI;
    return angle;
}
double euclideanDistance(QPointF p1,QPointF p2){
    return pow(pow(p1.x()-p2.x(),2)+pow(p1.y()-p2.y(),2),0.5);
}

bool withinRadius(QPointF p1,QPointF p2){
    if (util::euclideanDistance(p1,p2) <= 0.5){
        return true;
    }
    return false;
}

}
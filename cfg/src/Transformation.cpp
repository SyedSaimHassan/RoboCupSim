#include "Transformation.h"

Transformation& Transformation::instance() {
    static Transformation instance;
    return instance;
}

inline void Transformation::transformation(QPainter *p){
    p->setRenderHint(QPainter::Antialiasing);
    p->fillRect(rect(), Qt::green);

    const double w = cfg::Dimensions::screenWidth;
    const double h = cfg::Dimensions::screenHeight;

    const double Wx = cfg::Dimensions::fieldWidth;   
    const double Wy = cfg::Dimensions::fieldHeight;   

    const double sx = w / Wx;
    const double sy = h / Wy;
    s  = std::min(sx, sy);

    offSetX = (w - Wx * s) / 2.0;
    offSetY = (h - Wy * s) / 2.0;
    
    p->translate((Wx * s)/2.0 + offSetX, (Wy * s)/2.0 + offSetY);

    p->scale(s, -s);
}

QPointF Transformation::meterToPixel(double mx, double my) {
    double x = offSetX + (mx * s);
    double y = offSetY + (my * s);
    return QPointF(x, y);
}

QPointF Transformation::pixelToMeter(double px, double py) {
    double x = (px - offSetX) / s;
    double y = (py - offSetY) / s;
    return QPointF(x, y);
}
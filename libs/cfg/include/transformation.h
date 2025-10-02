#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include <QPainter>
#include <QWidget>
#include "dimensions.h"

class Transformation : public QWidget {
 public:
  static double s;
  static double offSetX;
  static double offSetY;

  static Transformation& instance();

  static void transformation(QPainter* p, const QRect& area);

  QPointF meterToPixel(double mx, double my);

  QPointF pixelToMeter(double px, double py);
};

#endif
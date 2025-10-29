#ifndef INV_H
#define INV_H
#include "systemConfig.h"
#include <vector>
#include <cmath>
#include <iostream>
namespace kin {
class Inv {
 public:
  void getVelocity();
  Eigen::Vector4d velocityToRpm(Eigen::Vector4d velocities);
};
}  // namespace kin
#endif
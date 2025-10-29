#ifndef FWD_H
#define FWD_H
#include "systemConfig.h"
#include <vector>
#include <cmath>
#include <iostream>
namespace kin {
class Fwd {
 public:
  std::vector<Eigen::Vector3d> getVelocity();
  Eigen::Vector4d rpmToRadPerSec(Eigen::Vector4d rpm);
};
}  // namespace kin
#endif
n
#ifndef TRAPEZOIDAL_TRAJECTORY_H
#define TRAPEZOIDAL_TRAJECTORY_H
#include <iostream>
#include <cmath>
#include "systemConfig.h"
#define dt 1 / cfg::SystemConfig::frameRate

namespace Traj {
class Trapezoidal_Traj {
 public:
  void SetVelocityFromTraj(int index);
};
}  // namespace Traj

#endif

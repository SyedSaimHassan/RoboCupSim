#include "TrapezoidalTrajectory.h"
namespace Traj {
void Trapezoidal_Traj::SetVelocityFromTraj(int index) {
  index--;
  if ((cfg::SystemConfig::teamOneWayPoints[index].size()) == 0) {
    return;
  }

  Eigen::Vector3d Dist;
  Dist =
      cfg::SystemConfig::teamOneWayPoints[index][0] - cfg::SystemConfig::teamOnePlayerPos[index];
  if (Dist.norm() < 0.05) {
    cfg::SystemConfig::teamOneWayPoints[index].erase(
        cfg::SystemConfig::teamOneWayPoints[index].begin());
    return;
  }
  double EuclidianDist = Dist.norm();
  double stoppingDist = cfg::SystemConfig::teamOnePlayerVel[index].squaredNorm() /
                        (2 * cfg::SystemConfig::playerMaxAcceleration);
  if (EuclidianDist > stoppingDist) {
    Eigen::Vector3d NewSpeed = cfg::SystemConfig::teamOnePlayerVel[index] +
                               cfg::SystemConfig::playerMaxAcceleration * Dist.normalized() * dt;
    cfg::SystemConfig::teamOnePlayerVel[index] =
        Eigen::Vector3d(std::clamp(float(NewSpeed.x()), -cfg::SystemConfig::playerMaxSpeed,
                                   cfg::SystemConfig::playerMaxSpeed),
                        std::clamp(float(NewSpeed.y()), -cfg::SystemConfig::playerMaxSpeed,
                                   cfg::SystemConfig::playerMaxSpeed),
                        std::clamp(float(NewSpeed.z()), -cfg::SystemConfig::playerMaxRotation,
                                   cfg::SystemConfig::playerMaxRotation));
  } else {
    auto Decelerate = [](float velocity, float maxAcc) {
      float decel = std::min(std::abs(velocity), maxAcc);
      if (velocity > 0) decel *= -1;
      return velocity + decel * dt;
    };

    cfg::SystemConfig::teamOnePlayerVel[index].x() = Decelerate(
        cfg::SystemConfig::teamOnePlayerVel[index].x(), cfg::SystemConfig::playerMaxAcceleration);
    cfg::SystemConfig::teamOnePlayerVel[index].y() = Decelerate(
        cfg::SystemConfig::teamOnePlayerVel[index].y(), cfg::SystemConfig::playerMaxAcceleration);
    cfg::SystemConfig::teamOnePlayerVel[index].z() =
        Decelerate(cfg::SystemConfig::teamOnePlayerVel[index].z(),
                   cfg::SystemConfig::playerMaxOmegaAcceleration);
  };
  // std::cout << "[Traj::Trapezoidal_Traj::SetVelocityFromTraj] "
  //           << cfg::SystemConfig::teamOnePlayerVel[index].x() << " "
  //           << cfg::SystemConfig::teamOnePlayerVel[index].y() << " " << std::endl;
}
}  // namespace Traj
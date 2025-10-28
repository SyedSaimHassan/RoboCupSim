
#include "Inv.h"
namespace kin {

std::vector<Eigen::Vector4d> Inv::getVelocity() {
  std::vector<Eigen::Vector4d> velocities;

  std::vector<float> thetas = cfg::SystemConfig::wheelAngles;
  double r = cfg::SystemConfig::distanceFromRobotCenter;
  double wheelRadius = cfg::SystemConfig::wheelDiameter / 2.0;

  for (int i = 0; i < int(cfg::SystemConfig::numRobots / 2); i++) {
    Eigen::Vector3d v = cfg::SystemConfig::teamOnePlayerVel[i] * (1000.0 / 16.0);
    double angle = cfg::SystemConfig::teamOnePlayerPos[i].z();
    // std::cout << v.x() << std::endl;
    Eigen::Matrix<double, 4, 3> T;
    T << -sin(thetas[0] + angle), cos(thetas[0] + angle), r, -sin(thetas[1] + angle),
        cos(thetas[1] + angle), r, -sin(thetas[2] + angle), cos(thetas[2] + angle), r,
        -sin(thetas[3] + angle), cos(thetas[3] + angle), r;

    Eigen::Vector4d wheelVel = velocityToRpm((T * v) / wheelRadius);
    velocities.push_back(wheelVel);
    if (wheelVel.norm() > 0) {
      std::cout << "[kin::Inv::getVelocity] Robot ID: " << i + 1 << "\n"
                << " Velocity M/S: " << v.x() << " " << v.y() << " " << v.z() << " "
                << wheelVel.w() << std::endl;
      std::cout << "[kin::Inv::getVelocity] Robot ID: " << i + 1 << "\n"
                << " RPMS: " << wheelVel.x() << " " << wheelVel.y() << " " << wheelVel.z() << " "
                << wheelVel.w() << std::endl;
    }
  }

  return velocities;
}

Eigen::Vector4d Inv::velocityToRpm(Eigen::Vector4d velocities) {
  Eigen::Vector4d RpmVel;
  for (int i = 0; i < velocities.size(); i++) {
    RpmVel(i) = (velocities(i) * 60) / (2 * M_PI);
  }
  return RpmVel;
}
}  // namespace kin

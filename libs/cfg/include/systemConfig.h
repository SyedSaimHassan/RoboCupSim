#ifndef SYSTEM_CONFIG_H
#define SYSTEM_CONFIG_H

#include <Eigen/Dense>

namespace cfg {
struct SystemConfig{
    static constexpr int numRobots = 8;

    // Ball
    static const Eigen::Vector2d initBallPosition;
    static const float ballRadius;
    static const float ballMass;
    // Robots
    static const float robotRadius;
    static const float playerMaxSpeed;
    static const float robotMass;
    // static const float playerMaxAcceleration;
    // static const float playerMaxShootForce;

  // Robot Team
  static std::vector<Eigen::Vector3d> teamOneStartFormation;
  static std::vector<Eigen::Vector3d> teamTwoStartFormation;
};
}  // namespace cfg

#endif
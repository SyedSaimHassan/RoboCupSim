#ifndef SYSTEM_CONFIG_H
#define SYSTEM_CONFIG_H

#include <Eigen/Dense>

namespace cfg {
struct SystemConfig {
  static const float frameRate;
  static constexpr int numRobots = 8;
  enum class RobotState {Autonomous, Manual};
  static std::vector<RobotState> PlayerStates;

  // Ball
  static const float ballMass;
  static const float ballRadius;
  static const float ballAcceleration;
  static const Eigen::Vector2d initBallPosition;

  // Robots
  static const float robotMass;
  static const float robotRadius;
  static const float playerMaxSpeed;
  static const float playerMaxRotation;
  static const float playerMaxAcceleration;
  static const float playerMaxOmegaAcceleration;
  // static const float playerMaxShootForce;

  // Trajectory
  static std::vector<Eigen::Vector3d> teamOnePlayerPos;
  static std::vector<Eigen::Vector3d> teamTwoPlayerPos;
  static std::vector<Eigen::Vector3d> teamOnePlayerVel;
  static std::vector<Eigen::Vector3d> teamTwoPlayerVel;

  // Robot Team
  static std::vector<Eigen::Vector3d> teamOneStartFormation;
  static std::vector<Eigen::Vector3d> teamTwoStartFormation;
};
}  // namespace cfg

#endif
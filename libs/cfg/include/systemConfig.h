#ifndef SYSTEM_CONFIG_H
#define SYSTEM_CONFIG_H

#include <Eigen/Dense>

namespace cfg {
struct SystemConfig {
  static const float frameRate;
  static const float wheelDiameter;
  static constexpr int numRobots = 8;
  static Eigen::Matrix<double, 6, 6> Q;
  static const float distanceFromRobotCenter;
  enum class RobotState {Autonomous, Manual};
  static const std::vector<float> wheelAngles;
  static std::vector<RobotState> PlayerStates;

  // Ball
  static const float ballMass;
  static const float ballRadius;
  static const float ballAcceleration;
  static Eigen::Vector2d currBallPosition;
  static Eigen::Vector2d currBallVel;
  static const Eigen::Vector2d initBallPosition;

  // Robots
  static const float robotMass;
  static const float robotRadius;
  static const float playerMaxSpeed;
  static const float playerMaxRotation;
  static const float ballPlayerElasticity;
  static const float playerMaxAcceleration;
  static const float playerPlayerElasticity;
  static const float playerMaxOmegaAcceleration;
  // static const float playerMaxShootForce;

  // Trajectory
  static std::vector<Eigen::Vector3d> teamOnePlayerPos;
  static std::vector<Eigen::Vector3d> teamTwoPlayerPos;
  static std::vector<Eigen::Vector3d> teamOnePlayerVel;
  static std::vector<Eigen::Vector3d> teamTwoPlayerVel;
  static std::vector<std::vector<Eigen::Vector3d>> teamOneWayPoints;
  static std::vector<std::vector<Eigen::Vector3d>> teamTwoWayPoints;

  // Robot Team
  static std::vector<Eigen::Vector3d> teamOneStartFormation;
  static std::vector<Eigen::Vector3d> teamTwoStartFormation;
  // Ball possession
  static bool ballHeld;
  static int ballHolder; // player ID who holds the ball, -1 if none
};
}  // namespace cfg

#endif

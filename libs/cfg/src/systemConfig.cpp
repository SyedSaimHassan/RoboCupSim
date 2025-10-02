#include "systemConfig.h"

// Ball config
const Eigen::Vector2d cfg::SystemConfig::initBallPosition = Eigen::Vector2d(0.0f, 0.0f);
const float cfg::SystemConfig::ballRadius = 0.05f;

// Robot config
const float cfg::SystemConfig::robotRadius = 0.204f;

// Team 1 initial formation
std::vector<Eigen::Vector3d> cfg::SystemConfig::teamOneStartFormation = []() {
  std::vector<Eigen::Vector3d> v(SystemConfig::numRobots);
  if (SystemConfig::numRobots >= 1) v[0] = Eigen::Vector3d(-0.5f, -0.0f, 0.0f);
  if (SystemConfig::numRobots >= 4) v[3] = Eigen::Vector3d(-0.7f, -0.3f, 0.0f);
  if (SystemConfig::numRobots >= 5) v[4] = Eigen::Vector3d(-0.7f, 0.3f, 0.0f);
  if (SystemConfig::numRobots >= 6) v[5] = Eigen::Vector3d(-0.9f, -0.0f, 0.0f);
  return v;
}();

// Team 2 initial formation
std::vector<Eigen::Vector3d> cfg::SystemConfig::teamTwoStartFormation = []() {
  std::vector<Eigen::Vector3d> v(SystemConfig::numRobots);
  if (SystemConfig::numRobots >= 1) v[0] = Eigen::Vector3d(0.5f, 0.0f, 0.0f);
  if (SystemConfig::numRobots >= 4) v[3] = Eigen::Vector3d(0.7f, -0.3f, 0.0f);
  if (SystemConfig::numRobots >= 5) v[4] = Eigen::Vector3d(0.7f, 0.3f, 0.0f);
  if (SystemConfig::numRobots >= 6) v[5] = Eigen::Vector3d(0.9f, -0.0f, 0.0f);
  return v;
}();
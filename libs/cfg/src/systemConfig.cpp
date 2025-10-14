#include "systemConfig.h"

const float cfg::SystemConfig::frameRate = 60;

// Ball config
const float cfg::SystemConfig::ballMass = 0.046f;
const float cfg::SystemConfig::ballRadius = 0.0215f;
const float cfg::SystemConfig::ballAcceleration = 0.1f;
const Eigen::Vector2d cfg::SystemConfig::initBallPosition = Eigen::Vector2d(1.0f, 0.0f);

// Robot config (speed is in m/s)
const float cfg::SystemConfig::robotMass = 1.5f;
const float cfg::SystemConfig::robotRadius = 0.204f;
const float cfg::SystemConfig::playerMaxSpeed = 2.0f;
const float cfg::SystemConfig::playerMaxRotation = 0.5f;
const float cfg::SystemConfig::ballPlayerElasticity = 0.5f;
const float cfg::SystemConfig::playerMaxAcceleration = 0.1f;

const float cfg::SystemConfig::playerMaxOmegaAcceleration = 0.1f;
// const float cfg::SystemConfig::playerMaxShootForce = 0.0f;

// Trajectory config
std::vector<Eigen::Vector3d> cfg::SystemConfig::teamOnePlayerPos = []() {
  std::vector<Eigen::Vector3d> v(SystemConfig::numRobots);
  v[0] = Eigen::Vector3d(-1.5f, -0.0f, 0.0f);
  v[1] = Eigen::Vector3d(-0.7f, -0.3f, 0.0f);
  v[2] = Eigen::Vector3d(-0.7f, 0.3f, 0.0f);
  v[3] = Eigen::Vector3d(-0.9f, -0.0f, 0.0f);
  return v;
}();

std::vector<Eigen::Vector3d> cfg::SystemConfig::teamTwoPlayerPos = []() {
  std::vector<Eigen::Vector3d> v(SystemConfig::numRobots);
  v[0] = Eigen::Vector3d(0.5f, 0.0f, 0.0f);
  v[1] = Eigen::Vector3d(0.7f, -0.3f, 0.0f);
  v[2] = Eigen::Vector3d(0.7f, 0.3f, 0.0f);
  v[3] = Eigen::Vector3d(0.9f, -0.0f, 0.0f);
  return v;
}();

std::vector<Eigen::Vector3d> cfg::SystemConfig::teamOnePlayerVel = []() {
  std::vector<Eigen::Vector3d> v(SystemConfig::numRobots);
  v[0] = Eigen::Vector3d(0.0f, 0.0f, 0.0f);
  v[1] = Eigen::Vector3d(0.0f, 0.0f, 0.0f);
  v[2] = Eigen::Vector3d(0.0f, 0.0f, 0.0f);
  v[3] = Eigen::Vector3d(0.0f, 0.0f, 0.0f);
  return v;
}();

std::vector<Eigen::Vector3d> cfg::SystemConfig::teamTwoPlayerVel = []() {
  std::vector<Eigen::Vector3d> v(SystemConfig::numRobots);
  v[0] = Eigen::Vector3d(0.0f, 0.0f, 0.0f);
  v[1] = Eigen::Vector3d(0.0f, 0.0f, 0.0f);
  v[2] = Eigen::Vector3d(0.0f, 0.0f, 0.0f);
  v[3] = Eigen::Vector3d(0.0f, 0.0f, 0.0f);
  return v;
}();

std::vector<std::vector<Eigen::Vector3d>> cfg::SystemConfig::teamOneWayPoints = {{},{},{},{}};
std::vector<std::vector<Eigen::Vector3d>> cfg::SystemConfig::teamTwoWayPoints = {{},{},{},{}};
// Team 1 initial formation
std::vector<Eigen::Vector3d> cfg::SystemConfig::teamOneStartFormation = []() {
  std::vector<Eigen::Vector3d> v(SystemConfig::numRobots);
  if (SystemConfig::numRobots >= 1) v[0] = Eigen::Vector3d(-1.5f, -0.0f, 0.0f);
  if (SystemConfig::numRobots >= 2) v[1] = Eigen::Vector3d(-0.7f, -0.3f, 0.0f);
  if (SystemConfig::numRobots >= 3) v[2] = Eigen::Vector3d(-0.7f, 0.3f, 0.0f);
  if (SystemConfig::numRobots >= 4) v[3] = Eigen::Vector3d(-0.9f, -0.0f, 0.0f);
  return v;
}();

// Team 2 initial formation
std::vector<Eigen::Vector3d> cfg::SystemConfig::teamTwoStartFormation = []() {
  std::vector<Eigen::Vector3d> v(SystemConfig::numRobots);
  if (SystemConfig::numRobots >= 1) v[0] = Eigen::Vector3d(0.5f, 0.0f, 0.0f);
  if (SystemConfig::numRobots >= 2) v[1] = Eigen::Vector3d(0.7f, -0.3f, 0.0f);
  if (SystemConfig::numRobots >= 3) v[2] = Eigen::Vector3d(0.7f, 0.3f, 0.0f);
  if (SystemConfig::numRobots >= 4) v[3] = Eigen::Vector3d(0.9f, -0.0f, 0.0f);
  return v;
}();
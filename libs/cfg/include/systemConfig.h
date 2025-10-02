#ifndef SYSTEM_CONFIG_H
#define SYSTEM_CONFIG_H

#include <Eigen/Dense>

namespace cfg {
struct SystemConfig{
    static constexpr int numRobots = 8;

    // Ball
    static const Eigen::Vector2d initBallPosition;
    static const float ballRadius;
    
    // Robots
    static const float robotRadius;

    // Robot Team
    static std::vector<Eigen::Vector3d> teamOneStartFormation;
    static std::vector<Eigen::Vector3d> teamTwoStartFormation;   
};
}

#endif
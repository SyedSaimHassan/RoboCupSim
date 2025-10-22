#ifndef INV_H
#define INV_H
#include "inv.h"

std::vector<Eigen::Vector4d> Inv::getVelocity() {
    std::vector<Eigen::Vector4d> velocities;

    std::vector<float> thetas = cfg::SystemConfig::wheelAngles;
    double r = cfg::SystemConfig::distanceFromRobotCenter;
    double wheelRadius = cfg::SystemConfig::wheelDiameter / 2.0;

    for (int i = 0; i < cfg::SystemConfig::numRobots; i++) {
        Eigen::Vector3d v = cfg::SystemConfig::teamOnePlayerVel[i]; 
        double angle = cfg::SystemConfig::teamOnePlayerPos[i].z();

        Eigen::Matrix<double, 4, 3> T;
        T << -sin(thetas[0] + angle), cos(thetas[0] + angle), r,
             -sin(thetas[1] + angle), cos(thetas[1] + angle), r,
             -sin(thetas[2] + angle), cos(thetas[2] + angle), r,
             -sin(thetas[3] + angle), cos(thetas[3] + angle), r;

        Eigen::Vector4d wheelVel = (T * v) / wheelRadius;
        velocities.push_back(velocityToRpm(wheelVel));
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

#endif

#include "Fwd.h"
namespace kin {

std::vector<Eigen::Vector3d> Fwd::getVelocity() {
    std::vector<Eigen::Vector3d> robotVelocities;

    const std::vector<float>& thetas = cfg::SystemConfig::wheelAngles;
    double r = cfg::SystemConfig::distanceFromRobotCenter;
    double wheelRadius = cfg::SystemConfig::wheelDiameter / 2.0;

    for (int i = 0; i < cfg::SystemConfig::numRobots; i++) {
        Eigen::Vector4d wheelRpm = cfg::SystemConfig::teamOneWheelRpm[i];
        double angle = cfg::SystemConfig::teamOnePlayerPos[i].z();
        Eigen::Vector4d wheelOmega = rpmToRadPerSec(wheelRpm);
        Eigen::Matrix<double, 4, 3> T;
        T << -sin(thetas[0] + angle), cos(thetas[0] + angle), r,
             -sin(thetas[1] + angle), cos(thetas[1] + angle), r,
             -sin(thetas[2] + angle), cos(thetas[2] + angle), r,
             -sin(thetas[3] + angle), cos(thetas[3] + angle), r;
            
        Eigen::Matrix3d TT_inv = (T.transpose() * T).inverse();
        Eigen::Vector3d v = wheelRadius * TT_inv * T.transpose() * wheelOmega;
        robotVelocities.push_back(v);
        if (v.norm() > 0.0){
            std::cout << "[kin::Fwd::getVelocity] Robot  V: " << v.x() << v.y() << v.z() << std::endl;
        }
    }
    
    return robotVelocities;
}

Eigen::Vector4d Fwd::rpmToRadPerSec(Eigen::Vector4d rpm) {
    Eigen::Vector4d omega;
    for (int i = 0; i < rpm.size(); i++) {
        omega(i) = rpm(i) * 2.0 * M_PI / 60.0;
    }
    return omega;
}

}  // namespace kin

#ifndef INV_H
#define INV_H
#include "inv.h"

std::vector<Eigen::Vector4d> Inv:: getVelocity(){

    std::vector<Eigen::Vector4d> velocities;
    std::vector<double>thetas;
    double radius=cfg::SystemConfig::distanceFromRobotCenter;
    
    for (int i=0;i<cfg::SystemConfig::numRobots;i++){
        
        Eigen::Vector3d playerVol=cfg::SystemConfig::teamOnePlayerVel[i];
        double angle=cfg::SystemConfig::teamOnePlayerPos[i].z();
        Eigen::Matrix<double, 4, 3> T;

        T << -sin(thetas[0]+angle),cos(angle+thetas[0]),radius,
              -sin(thetas[1]+angle),cos(angle+thetas[1]),radius,
              -sin(thetas[2]+angle),cos(angle+thetas[2]),radius,
              -sin(thetas[3]+angle),cos(angle+thetas[3]),radius;
          
        
        velocities.push_back(velocityToRpm(T*playerVol));
    }
    return velocities;
}

Eigen::Vector4d Inv::velocityToRpm(Eigen::Vector4d velocities){
    Eigen::Vector4cd RpmVel;
    for (int i=0;i<velocities.size();i++){
        RpmVel(i)=(velocities(i)*60)/(M_PI*cfg::SystemConfig::w);
    }
    return RpmVel;
}

#endif
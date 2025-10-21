#ifndef INV_H
#define INV_H
#include "inv.h"

std::vector<Eigen::Vector4d> Inv:: getVelocity(){
    std::vector<Eigen::Vector4d> velocities;
    std::vector<Eigen::Vector3d>playerVol=cfg::SystemConfig::teamOnePlayerVel;
    for (int i=0;i<playerVol.size();i++){
        double angle=cfg::SystemConfig::teamOnePlayerPos[i].z();
        
    }
}

#endif
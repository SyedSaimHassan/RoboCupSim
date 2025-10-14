#include"TrapoizdalTragectory.h"
Eigen::Vector3d Tra_Tra::traj(int index){
    Eigen::Vector3d currentpos = cfg::SystemConfig::teamOnePlayerPos[index];
    Eigen::Vector3d currentvel = cfg::SystemConfig::teamOnePlayerVel[index];
    double maxvelincom = pow(pow(cfg::SystemConfig::playerMaxSpeed,2)/2,0.5);
    if ((cfg::SystemConfig::teamOneWayPoints[index-1].size()) == 1){
        return Eigen::Vector3d(0,0,0);
    }
    Eigen::Vector3d goalpos=cfg::SystemConfig::teamOneWayPoints[index-1][0];
    double remaing_dis = pow((pow(currentpos.x()-goalpos.x(),2))+(pow(currentpos.y()-goalpos.y(),2)),0.5);
    double dis_travl = (pow(currentvel.x(),2)+pow(currentvel.y(),2))/2*cfg::SystemConfig::playerMaxAcceleration;
    double finalvelX;
    double finalvelY;
    double maxaccincom=pow(pow(cfg::SystemConfig::playerMaxAcceleration,2)/2,0.5);
    if (remaing_dis>dis_travl){
        finalvelX=std::min(currentvel.x()+maxaccincom*dt,maxvelincom);
        finalvelX=std::min(currentvel.x()+maxaccincom*dt,maxvelincom);
    }    
    else{
        finalvelX=std::max(currentvel.x()-maxaccincom*dt,0.0);
        finalvelX=std::max(currentvel.x()-maxaccincom*dt,0.0);
    }
    return Eigen::Vector3d(finalvelX,finalvelY,currentvel.z());
}
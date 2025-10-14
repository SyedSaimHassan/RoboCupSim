#include"TrapoizdalTragectory.h"
Eigen::Vector3d Tra_Tra::traj(int index){
    Eigen::Vector3d currentpos = cfg::SystemConfig::teamOnePlayerPos[index];
    Eigen::Vector3d currentvel = cfg::SystemConfig::teamOnePlayerVel[index];
    double maxvel = cfg::SystemConfig::playerMaxSpeed;
    Eigen::Vector3d goalpos=Waypoint[0][0];
    double remaing_dis = pow((pow(currentpos.x()-goalpos.x(),2))+((pow(currentpos.y()-goalpos.y(),2)),0.5));
    double dis_travl = (pow(currentvel.x(),2)+pow(currentvel.y(),2))/2*cfg::SystemConfig::playerMaxAcceleration;
    
    if (remaing_dis>dis_travl){
        
    }   

}
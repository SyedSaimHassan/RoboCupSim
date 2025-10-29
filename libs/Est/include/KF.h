#ifndef KF_H
#define KF_H
#include<vector>
#include<Eigen/Dense>
#include"systemConfig.h"
#include<iostream>
namespace kf{
class KF{
    public:
    
    void predictPosition(Eigen::Vector3d x, Eigen::Vector3d z , Eigen::Vector3d vel);
};
}
#endif
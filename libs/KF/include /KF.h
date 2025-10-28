#ifndef KF_H
#define KF_H
#include<vector>
#include<Eigen/Dense>
class KF{
    Eigen::Vector3d predictPosition(Eigen::Vector3d x, Eigen::Vector3d z , Eigen::Vector3d vel);
};
#endif
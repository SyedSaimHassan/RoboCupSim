#include "KF.h"
using namespace kf;
int main(){
    Eigen::Vector3d x;
    x << 1.00, 0.50, 0.02;

    Eigen::Vector3d vel;
    vel << 0.50, -1.0, 0.010;

    Eigen::Vector3d z;
    z<< 1.08, 0.48, 0.025;
    KF k; 
    k.predictPosition(x,z,vel);
    
}
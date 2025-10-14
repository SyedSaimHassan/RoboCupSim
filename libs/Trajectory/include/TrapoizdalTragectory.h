#include"systemConfig.h"
#include<cmath>
class Tra_Tra{
    public:
    double dt=1/cfg::SystemConfig::frameRate;
    Eigen::Vector3d traj(int index);
};
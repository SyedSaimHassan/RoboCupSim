#include"systemConfig.h"
#include<vector>
#include <cmath>

class Inv{
    public:
        std::vector<Eigen::Vector4d> getVelocity();
        Eigen::Vector4d velocityToRpm(Eigen::Vector4d velcoities);
};
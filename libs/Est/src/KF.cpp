#include "KF.h"
namespace kf{
void KF::predictPosition(){
    for (int i=0;i<1;i++){

        double t = 0.0167;
        Eigen::Matrix<double, 6 , 6> F;
        F<< 1,0,0,t,0,0,
            0,1,0,0,t,0,
            0,0,1,0,0,t,
            0,0,0,1,0,0,
            0,0,0,0,1,0,
            0,0,0,0,0,1;
            
            Eigen::Matrix<double,3,6>H;
            H<< 1,0,0,0,0,0,
            0,1,0,0,0,0,
            0,0,1,0,0,0;
            
            Eigen::VectorXd q_diag(6);
            q_diag<<0.001 ,0.001 ,0.0001 ,0.001 ,0.001 ,1e-5;     //  How noisy your motion model is
        Eigen::MatrixXd Q = q_diag.asDiagonal();
        
        Eigen::VectorXd r_diag(3);
        r_diag<<0.0004 ,0.0004 ,0.0001;     //  How noisy your sensor is
        Eigen::MatrixXd R = r_diag.asDiagonal();
        
        Eigen::VectorXd X_k(6);
        X_k <<  cfg::SystemConfig::teamOnePlayerPos[i](0), cfg::SystemConfig::teamOnePlayerPos[i](1), cfg::SystemConfig::teamOnePlayerPos[i](2), cfg::SystemConfig::teamOnePlayerVel[i](0), cfg::SystemConfig::teamOnePlayerVel[i](1), cfg::SystemConfig::teamOnePlayerVel[i](2);

        X_k = F * X_k;

        Eigen::MatrixXd P_k = (F * cfg::SystemConfig::P[i] * F.transpose()) + Q;
        
        Eigen::MatrixXd S = H * P_k * H.transpose() + R;
        
        Eigen::MatrixXd K = P_k * H.transpose() * S.inverse();
        
        Eigen::VectorXd v = cfg::SystemConfig::CameraData[i] - (H * X_k);
        
        Eigen::VectorXd X_K_1 = X_k + (K * v);
        
        Eigen::Matrix<double,6,6>I;
        I<< 1,0,0,0,0,0,
            0,1,0,0,0,0,
            0,0,1,0,0,0,
            0,0,0,1,0,0,
            0,0,0,0,1,0,
            0,0,0,0,0,1;
        
        cfg::SystemConfig::P[i] = ((I - (K * H)) * P_k * (I - (K * H)).transpose()) + (K * R * K.transpose());
        
}

}
}
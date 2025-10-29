#ifndef SENSOR_H
#define SENSOR_H
#include <iostream>
#include "systemConfig.h"


namespace HW{

    enum class SensorType {Real,Model};
class SensorManager{

    public:
    void update();  
    SensorManager();
    private:
    SensorType GyroType ;
    SensorType CameraType ;
    SensorType EncoderType;
    void AssignTypes();
    void GetGyroUpdate();
    void GetEncoderUpdate();
    void GetCameraUpdate();


};








}






#endif
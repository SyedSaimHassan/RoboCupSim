#include "Sensor.h"

namespace HW {

void SensorManager::update() {
  GetCameraUpdate();
  GetGyroUpdate();
  GetEncoderUpdate();
};
void SensorManager::AssignTypes() {
#ifdef BUILD_ON_PI
  GyroType = SensorType::Real;
  CameraType = SensorType::Real;
  EncoderType = SensorType::Real;

#else
  GyroType = SensorType::Model;
  CameraType = SensorType::Model;
  EncoderType = SensorType::Model;
#endif
}

void SensorManager::GetCameraUpdate() {
  if (CameraType == SensorType::Real) {
  } else {
    for (int i = 0; i < int(cfg::SystemConfig::numRobots / 2); i++) {
      cfg::SystemConfig::CameraData[i] = (cfg::SystemConfig::teamOnePlayerPos[i]);
    }
  }
}

void SensorManager::GetGyroUpdate() {
  if (GyroType == SensorType::Real) {
  } else {
    for (int i = 0; i < int(cfg::SystemConfig::numRobots / 2); i++) {
      cfg::SystemConfig::GyroData[i] = (cfg::SystemConfig::teamOnePlayerPos[i].z());
    }
  }
}
void SensorManager::GetEncoderUpdate() {
  if (EncoderType == SensorType::Real) {
  } else {
    for (int i = 0; i < int(cfg::SystemConfig::numRobots / 2); i++) {
      cfg::SystemConfig::EncoderData[i] = cfg::SystemConfig::teamOneWheelRpm[i];
    }
  }
}
SensorManager::SensorManager() {
  AssignTypes();
  for (int i = 0; i < int(cfg::SystemConfig::numRobots / 2); i++) {
    cfg::SystemConfig::CameraData.push_back(
        Eigen::Vector3d(cfg::SystemConfig::teamOnePlayerPos[i]));
    cfg::SystemConfig::GyroData.push_back(0.0f);
    cfg::SystemConfig::EncoderData.push_back(Eigen::Vector4d(0, 0, 0, 0));
  }
}

}  // namespace HW

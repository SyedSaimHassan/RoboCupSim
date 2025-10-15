#include"Collision.h"
#include <bits/stdc++.h>
#include <Eigen/Dense>
using namespace std;
namespace Physics{
std::bool checkCollision(Eigen::Vector3d playerPos1,Eigen::Vector3d playerPos2) {
    int radius=cfg::SystemConfig::robotRadius;
    float dx = playerPos2.x() - playerPos1.x();
    float dy = playerPos2.y() - playerPos1.y();
    float distanceSquared = dx * dx + dy * dy;
    float radiusSum = 2 * radius;
    return distanceSquared <= (radiusSum * radiusSum);
}

std::vector<std::pair<int,int>> Do(std::vector<Eigen::Vector3d>PlayerPositions){
    std::vector<std::pair<int,int>> coll;
    for (int RobotIndex1 = 1; RobotIndex1 <= int(cfg::SystemConfig::numRobots / 2); RobotIndex1++) {
        for (int RobotIndex2 = 1; RobotIndex2 <= int(cfg::SystemConfig::numRobots / 2); RobotIndex2++) {
            if(checkCollision(PlayerPositions[RobotIndex1-1],PlayerPositions[RobotIndex2-1])){
                coll.push_back({RobotIndex1-1,RobotIndex2-1});
            }
        }
    }
    return coll;
}

}
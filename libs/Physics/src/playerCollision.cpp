#include"playerCollision.h"
#include <Eigen/Dense>
#include <bits/stdc++.h>
using namespace std;
namespace Physics{
void checkPlayerCollisions(std::vector<Eigen::Vector3d> PlayerPositions,
                           std::vector<Eigen::Vector3d> PlayerVelocities) {
    int numPlayers = cfg::SystemConfig::numRobots / 2;
    for (int i = 0; i < numPlayers; i++) {
        for (int j = i + 1; j < numPlayers; j++) {
            double dist = util::euclideanDistance(PlayerPositions[i], PlayerPositions[j]);
            if (dist <= 2 * cfg::SystemConfig::robotRadius) {
                deflectPlayers(PlayerPositions, PlayerVelocities, i, j);
            }
        }
    }
}

void deflectPlayers(std::vector<Eigen::Vector3d> PlayerPositions,
                    std::vector<Eigen::Vector3d> PlayerVelocities,
                    int i, int j) {
    Eigen::Vector2d p1 = PlayerPositions[i].head<2>();
    Eigen::Vector2d p2 = PlayerPositions[j].head<2>();
    Eigen::Vector2d v1 = PlayerVelocities[i].head<2>();
    Eigen::Vector2d v2 = PlayerVelocities[j].head<2>();

    double radius = cfg::SystemConfig::robotRadius;
    double e = 0.1;

    Eigen::Vector2d n = p2 - p1;
    double dist = n.norm();
    if (dist == 0 || dist > 2 * radius) return;
    n /= dist;

    Eigen::Vector2d relVel = v1 - v2;
    double velAlongNormal = relVel.dot(n);
    if (velAlongNormal > 0) return;

    double jmag = -0.5 * (1 + e) * velAlongNormal;
    Eigen::Vector2d impulse = jmag * n;
    v1 += impulse;
    v2 -= impulse;

    double overlap = 2 * radius - dist;
    p1 -= n * (overlap / 2);
    p2 += n * (overlap / 2);
    PlayerPositions[i].head<2>() = p1;
    PlayerPositions[j].head<2>() = p2;
    PlayerVelocities[i].head<2>() = v1;
    PlayerVelocities[j].head<2>() = v2;
}
}
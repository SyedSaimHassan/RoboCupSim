
#ifndef PLAYERCOLLISION_H
#define PLAYERCOLLISION_H

#include <map>
#include "player.h"

namespace Physics {

//Move the player (done by controller as of now)
// void UpdateKinematics(float dt);

// Check and resolve collisions
void CheckPlayerCollision();


// clamp the robot within boundaries


// bool IsBallInFrontOfRobot(state::SoccerObject& robot, state::SoccerObject& ball);
// void HandleBallSticking(state::SoccerObject& robot, state::SoccerObject& ball);
// void UpdateAttachedBallPosition(state::SoccerObject& robot, state::SoccerObject& ball);
// void DetachBall(state::SoccerObject& ball, float detach_velocity = 2.0f);

}

#endif 
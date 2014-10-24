/*
 * rotation.hpp
 *
 *  Created on: Oct 2, 2014
 *      Author: dheerendra
 */

#ifndef TRANSFORM_HPP_
#define TRANSFORM_HPP_
#include <string>
using namespace std;

extern double main_rotation;
extern int body_rotated;


extern double upper_leg;
extern double lower_leg;
extern double leg_back;
extern int leg_rotated;

extern double upper_arm;
extern double lower_arm;
extern double arm_front;
extern int arm_rotated;

extern double arm_close;
extern double arm_back;
extern double lower_arm_back;

extern double hood_pull;
extern double flaps_pull;
extern double flaps_rotate;
extern int flaps_rotated;

//transformation event;
extern int legs;
extern int arms;
extern int flaps;
extern int body;


//Indivisual rotation
extern double rotation;
extern string selected;
extern double lLeg1f;
extern double lLeg2f;
extern double lLeg3f;
extern double lLegLower1f;

extern double rLeg1f;
extern double rLeg2f;
extern double rLeg3f;
extern double rLegLower1f;

extern double rArm1f;
extern double rArm2f;
extern double rArm3f;
extern double rArmLower1f;

extern double lArm1f;
extern double lArm2f;
extern double lArm3f;
extern double lArmLower1f;

extern double torso1f;
extern double torso2f;
extern double torso3f;

extern double neck1f;
extern double neck2f;
extern double neck3f;

//Car movement
extern double car_z;
extern double car_x;
extern double touching_ground;
extern int camera_setup;
extern double turned;
extern int speed;
#endif /* TRANSFORM_HPP_ */

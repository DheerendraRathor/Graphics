/*
 * rotation.cpp
 *
 *  Created on: Oct 2, 2014
 *      Author: dheerendra
 */

#include "transform.hpp"


int body = 0;
int body_rotated = 0;
double main_rotation = 0.0;

double upper_leg = 0.0;
double lower_leg = 0.0;
double leg_back = 0.0;
int leg_rotated = 0;


double upper_arm =  0.0;
double lower_arm = 0.0;
double arm_front = 0.0;
int arm_rotated = 0;

double arm_close = 0.0;
double arm_back = 0.0;
double lower_arm_back = 0.0;

double hood_pull = 0.0;
double flaps_pull = 0.0;
double flaps_rotate = 0.0;
int flaps_rotated = 0;

int legs = 0;
int arms = 0;
int flaps = 0;

string selected = "";
double rotation = 1.0;

double lLeg1f = 0.0;
double lLeg2f = 0.0;
double lLeg3f = 0.0;
double lLegLower1f = 0.0;

double rLeg1f = 0.0;
double rLeg2f = 0.0;
double rLeg3f = 0.0;
double rLegLower1f = 0.0;

double rArm1f = 0.0;
double rArm2f = 0.0;
double rArm3f = 0.0;
double rArmLower1f = 0.0;

double lArm1f = 0.0;
double lArm2f = 0.0;
double lArm3f = 0.0;
double lArmLower1f = 0.0;

double torso1f = 0.0;
double torso2f = 0.0;
double torso3f = 0.0;

double neck1f = 0.0;
double neck2f = 0.0;
double neck3f = 0.0;

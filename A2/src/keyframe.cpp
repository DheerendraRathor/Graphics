/*
 * keyframe.cpp
 *
 *  Created on: Nov 7, 2014
 *      Author: dheerendra
 */

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include "keyframe.hpp"
#include "transform.hpp"
using namespace std;

int line_number = 0;

void record_key_frame(){

    FILE *frameFile;
    frameFile = fopen("keyframes.txt", "a");
    fprintf(frameFile, "main_rotation body_rotated upper_leg lower_leg leg_back leg_rotated upper_arm lower_arm"
            " arm_front arm_rotated arm_close arm_back lower_arm_back hood_pull flaps_pull flaps_rotate"
            " flaps_rotated legs arms flaps body rotation selected lLeg1f lLeg2f lLeg3f lLegLower1f rLeg1f"
            " rLeg2f rLeg3f rLegLower1f rArm1f rArm2f rArm3f rArmLower1f lArm1f lArm2f lArm3f lArmLower1f"
            " torso1f torso2f torso3f neck1f neck2f neck3f leg_wheel_turn car_z car_x touching_ground"
            " camera_setup turned speed l0_enable l1_enable headlight turn_command top_cam sunlight");
    fprintf(frameFile, "\n");
    fprintf(frameFile, "%f %d %f %f %f %d %f %f %f %d %f %f %f %f %f %f %d %d %d %d %d %f %s %f %f %f %f %f %f"
            " %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %d %f %d %d %d %d %d %f %f",
             main_rotation, body_rotated, upper_leg, lower_leg, leg_back, leg_rotated, upper_arm, lower_arm,
             arm_front, arm_rotated, arm_close, arm_back, lower_arm_back, hood_pull, flaps_pull, flaps_rotate,
             flaps_rotated, legs, arms, flaps, body, rotation, selected.c_str(), lLeg1f, lLeg2f, lLeg3f,
             lLegLower1f, rLeg1f, rLeg2f, rLeg3f, rLegLower1f, rArm1f, rArm2f, rArm3f, rArmLower1f,
             lArm1f, lArm2f, lArm3f, lArmLower1f, torso1f, torso2f, torso3f, neck1f, neck2f, neck3f,
             leg_wheel_turn, car_x, car_x, touching_ground, camera_setup, turned, speed, l0_enable, l1_enable,
             headlight, turn_command, top_cam, sunlight);
    fprintf(frameFile, "\n");
    fclose(frameFile);

}

void playback(){
    int linecount = 0;
    string line;
    ifstream myfile("keyframes.txt");

    while (getline(myfile, line))
        ++linecount;

    ifstream readfile("keyframes.txt");
    int line_to_read = (line_number*2) % linecount + 1;

    for(int i = 0; i < line_to_read; ++i)
          getline(readfile, line);

    getline(readfile, line);

    stringstream ss(line);

    ss >> main_rotation >> body_rotated >> upper_leg >> lower_leg >> leg_back >> leg_rotated
    >> upper_arm >> lower_arm >> arm_front >> arm_rotated >> arm_close >> arm_back
    >> lower_arm_back >> hood_pull >> flaps_pull >> flaps_rotate >> flaps_rotated
    >> legs >> arms >>flaps >> body >> rotation >> selected >> lLeg1f >> lLeg2f >> lLeg3f
    >> lLegLower1f >> rLeg1f >> rLeg2f >> rLeg3f >> rLegLower1f >> rArm1f >> rArm2f >> rArm3f >> rArmLower1f >>
    lArm1f >> lArm2f >> lArm3f >> lArmLower1f >> torso1f >> torso2f >> torso3f >> neck1f >> neck2f >> neck3f >>
    leg_wheel_turn >> car_x >> car_x >> touching_ground >> camera_setup >> turned >> speed >> l0_enable >> l1_enable >>
    headlight >> turn_command >> top_cam >> sunlight;

    line_number++;
}

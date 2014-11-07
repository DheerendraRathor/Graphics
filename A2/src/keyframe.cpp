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
#include <GL/glew.h>
#include "keyframe.hpp"
#include "transform.hpp"
using namespace std;

//external variable
int fps = 20;

//internal variable
int line_number = 0;
int frame_count = 0;
double diff_d[43];
int diff_speed;

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

void playback_prepare(){
    int linecount = 0;
    string line;
    ifstream myfile("keyframes.txt");

    while (getline(myfile, line))
        ++linecount;

    if (linecount == 0){
        cerr<<"Nothing found in keyframes.txt (may be empty file)"<<endl;
        return;
    }

    ifstream readfile("keyframes.txt");
    int line_to_read = (line_number*2) % linecount + 1;

    for(int i = 0; i < line_to_read; ++i)
          getline(readfile, line);

    getline(readfile, line);

    stringstream ss(line);

    ss >> diff_d[0] >> body_rotated >> diff_d[1] >> diff_d[2] >> diff_d[3] >> leg_rotated
    >> diff_d[4] >> diff_d[5] >> diff_d[6] >> arm_rotated >> diff_d[7] >> diff_d[8]
    >> diff_d[9] >> diff_d[10] >> diff_d[11] >> diff_d[12] >> flaps_rotated
    >> legs >> arms >>flaps >> body >> diff_d[13] >> selected >> diff_d[14] >> diff_d[15] >> diff_d[16]
    >> diff_d[17] >> diff_d[18] >> diff_d[19] >> diff_d[20] >> diff_d[21] >> diff_d[22] >> diff_d[23]
    >> diff_d[24] >> diff_d[25] >> diff_d[26] >> diff_d[27] >> diff_d[28] >> diff_d[29] >> diff_d[30] >> diff_d[31]
    >> diff_d[32] >> diff_d[33] >> diff_d[34] >> diff_d[35] >> diff_d[36] >> diff_d[37] >> diff_d[38] >> diff_d[39]
    >> camera_setup >> diff_d[40] >> speed >> l0_enable >> l1_enable >>headlight
    >> turn_command >> diff_d[41] >> diff_d[42];

    line_number++;

    frame_count = 0;

    diff_d[0] = (diff_d[0] - main_rotation)/fps;
    diff_d[1] = (diff_d[1] - upper_leg)/fps;
    diff_d[2] = (diff_d[2] - lower_leg)/fps;
    diff_d[3] = (diff_d[3] - leg_back)/fps;
    diff_d[4] = (diff_d[4] - upper_arm)/fps;
    diff_d[5] = (diff_d[5] - lower_arm)/fps;
    diff_d[6] = (diff_d[6] - arm_front)/fps;
    diff_d[7] = (diff_d[7] - arm_close)/fps;
    diff_d[8] = (diff_d[8] - arm_back)/fps;
    diff_d[9] = (diff_d[9] - lower_arm_back)/fps;
    diff_d[10] = (diff_d[10] - hood_pull)/fps;
    diff_d[11] = (diff_d[11] - flaps_pull)/fps;
    diff_d[12] = (diff_d[12] - flaps_rotate)/fps;
    diff_d[13] = (diff_d[13] - rotation)/fps;
    diff_d[14] = (diff_d[14] - lLeg1f)/fps;
    diff_d[15] = (diff_d[15] - lLeg2f)/fps;
    diff_d[16] = (diff_d[16] - lLeg3f)/fps;
    diff_d[17] = (diff_d[17] - lLegLower1f)/fps;
    diff_d[18] = (diff_d[18] - rLeg1f)/fps;
    diff_d[19] = (diff_d[19] - rLeg2f)/fps;
    diff_d[20] = (diff_d[20] - rLeg3f)/fps;
    diff_d[21] = (diff_d[21] - rLegLower1f)/fps;
    diff_d[22] = (diff_d[22] - rArm1f)/fps;
    diff_d[23] = (diff_d[23] - rArm2f)/fps;
    diff_d[24] = (diff_d[24] - rArm3f)/fps;
    diff_d[25] = (diff_d[25] - rArmLower1f)/fps;
    diff_d[26] = (diff_d[26] - lArm1f)/fps;
    diff_d[27] = (diff_d[27] - lArm2f)/fps;
    diff_d[28] = (diff_d[28] - lArm3f)/fps;
    diff_d[29] = (diff_d[29] - lArmLower1f)/fps;
    diff_d[30] = (diff_d[30] - torso1f)/fps;
    diff_d[31] = (diff_d[31] - torso2f)/fps;
    diff_d[32] = (diff_d[32] - torso3f)/fps;
    diff_d[33] = (diff_d[33] - neck1f)/fps;
    diff_d[34] = (diff_d[34] - neck2f)/fps;
    diff_d[35] = (diff_d[35] - neck3f)/fps;
    diff_d[36] = (diff_d[36] - leg_wheel_turn)/fps;
    diff_d[37] = (diff_d[37] - car_z)/fps;
    diff_d[38] = (diff_d[38] - car_x)/fps;
    diff_d[39] = (diff_d[39] - touching_ground)/fps;
    diff_d[40] = (diff_d[40] - turned)/fps;
    diff_d[41] = (diff_d[41] - top_cam)/fps;
    diff_d[42] = (diff_d[42] - sunlight)/fps;
    //diff_speed = (diff_speed - speed) /fps;

}

void playback(){
    if (frame_count == fps){
        playback_prepare();
    }
    main_rotation += diff_d[0];
    upper_leg += diff_d[1];
    lower_leg += diff_d[2];
    leg_back += diff_d[3];
    upper_arm += diff_d[4];
    lower_arm += diff_d[5];
    arm_front += diff_d[6];
    arm_close += diff_d[7];
    arm_back += diff_d[8];
    lower_arm_back += diff_d[9];
    hood_pull += diff_d[10];
    flaps_pull += diff_d[11];
    flaps_rotate += diff_d[12];
    rotation += diff_d[13];
    lLeg1f += diff_d[14];
    lLeg2f += diff_d[15];
    lLeg3f += diff_d[16];
    lLegLower1f += diff_d[17];
    rLeg1f += diff_d[18];
    rLeg2f += diff_d[19];
    rLeg3f += diff_d[20];
    rLegLower1f += diff_d[21];
    rArm1f += diff_d[22];
    rArm2f += diff_d[23];
    rArm3f += diff_d[24];
    rArmLower1f += diff_d[25];
    lArm1f += diff_d[26];
    lArm2f += diff_d[27];
    lArm3f += diff_d[28];
    lArmLower1f += diff_d[29];
    torso1f += diff_d[30];
    torso2f += diff_d[31];
    torso3f += diff_d[32];
    neck1f += diff_d[33];
    neck2f += diff_d[34];
    neck3f += diff_d[35];
    leg_wheel_turn += diff_d[36];
    car_z += diff_d[37];
    car_x += diff_d[38];
    touching_ground += diff_d[39];
    turned += diff_d[40];
    top_cam += diff_d[41];
    sunlight += diff_d[42];
    //speed += diff_speed;

    frame_count++;
}

void capture_frame(int framenum, int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
  unsigned char *pRGB = new unsigned char [3 * (SCREEN_WIDTH+1) * (SCREEN_HEIGHT + 1) ];

  // set the framebuffer to read
  //default for double buffered
  glReadBuffer(GL_BACK);

  glPixelStoref(GL_PACK_ALIGNMENT,1);//for word allignment

  glReadPixels(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, pRGB);
  char filename[200];
  sprintf(filename,"./record/frame_%04d.ppm",framenum);
  std::ofstream out(filename, std::ios::out);
  out<<"P6"<<std::endl;
  out<<SCREEN_WIDTH<<" "<<SCREEN_HEIGHT<<" 255"<<std::endl;
  out.write(reinterpret_cast<char const *>(pRGB), (3 * (SCREEN_WIDTH+1) * (SCREEN_HEIGHT + 1)) * sizeof(int));
  out.close();


  delete pRGB;
}

/*
 * display_list.hpp
 *
 *  Created on: Oct 3, 2014
 *      Author: dheerendra
 */

#ifndef DISPLAY_LIST_HPP_
#define DISPLAY_LIST_HPP_

#include <GL/glew.h>
extern GLuint side_flap_list;
extern GLuint hood_list;
extern GLuint upper_arm_list;
extern GLuint lower_arm_list;
extern GLuint upper_leg_list;
extern GLuint lower_leg_list;
extern GLuint feet_list;
extern GLuint leg_wheel_list;
extern GLuint arm_wheel_list;
extern GLuint eye_list;
extern GLuint head_list;
extern GLuint mouth_list;
extern GLuint torso_list;
extern GLuint neck_list;

void genDisplayList();

#endif /* DISPLAY_LIST_HPP_ */

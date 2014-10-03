/*
 * display_list.cpp
 *
 *  Created on: Oct 3, 2014
 *      Author: dheerendra
 */

#include "display_list.hpp"
#include "draw_rectangle.hpp"
#include "draw_cube.hpp"
#include "wheel.hpp"

GLuint side_flap_list;
GLuint hood_list;
GLuint upper_arm_list;
GLuint lower_arm_list;
GLuint upper_leg_list;
GLuint lower_leg_list;
GLuint feet_list;
GLuint leg_wheel_list;
GLuint arm_wheel_list;
GLuint eye_list;
GLuint head_list;
GLuint mouth_list;
GLuint torso_list;
GLuint neck_list;

void genDisplayList() {

    side_flap_list = glGenLists(1);
    hood_list = glGenLists(1);
    upper_arm_list = glGenLists(1);
    lower_arm_list = glGenLists(1);
    upper_leg_list = glGenLists(1);
    lower_leg_list = glGenLists(1);
    feet_list = glGenLists(1);
    leg_wheel_list = glGenLists(1);
    arm_wheel_list = glGenLists(1);
    eye_list = glGenLists(1);
    head_list = glGenLists(1);
    mouth_list = glGenLists(1);
    torso_list = glGenLists(1);
    neck_list = glGenLists(1);

    glNewList(side_flap_list, GL_COMPILE);
    draw_rectangle(0.2, 0.5);
    glEndList();

    glNewList(hood_list, GL_COMPILE);
    glBegin(GL_POLYGON);
    glVertex3d(-0.2, -0.25, 0.0);
    glVertex3d(0.2, -0.25, 0.0);
    glVertex3d(0.06, 0.22, 0.0);
    glVertex3d(-0.06, 0.22, 0.0);
    glEnd();
    glEndList();

    glNewList(upper_arm_list, GL_COMPILE);
    draw_cube(0.1, 0.1, 0.3);
    glEndList();

    glNewList(lower_arm_list, GL_COMPILE);
    draw_cube(0.1, 0.1, 0.3);
    glEndList();

    glNewList(upper_leg_list, GL_COMPILE);
    draw_cube(0.1, 0.15, 0.3);
    glEndList();

    glNewList(lower_leg_list, GL_COMPILE);
    draw_cube(0.1, 0.1, 0.3);
    glEndList();

    glNewList(feet_list, GL_COMPILE);
    draw_cube(0.1, 0.2, 0.02);
    glEndList();

    glNewList(leg_wheel_list, GL_COMPILE);
    draw_wheel(0.1);
    glEndList();

    glNewList(arm_wheel_list, GL_COMPILE);
    draw_wheel(0.2);
    glEndList();

    glNewList(eye_list, GL_COMPILE);
    draw_cube(0.02,0.02,0.02);
    glEndList();

    glNewList(head_list, GL_COMPILE);
    draw_cube(0.2,0.2,0.2);
    glEndList();

    glNewList(mouth_list, GL_COMPILE);
    draw_cube(0.1,0.02,0.02);
    glEndList();

    glNewList(neck_list, GL_COMPILE);
    draw_cube(0.1, 0.1, 0.1);
    glEndList();

    glNewList(torso_list, GL_COMPILE);
    draw_cube(0.4, 0.2, 0.5);
    glEndList();

}


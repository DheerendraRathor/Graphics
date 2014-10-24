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
#include "texture.hpp"
#include "GL/glew.h"

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
    glColor3f(0.2, 0.2, 0.1);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    draw_rectangle(0.2, 0.5);
    glEndList();

    glNewList(hood_list, GL_COMPILE);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glColor3f(0.2, 0.2, 0.5);
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f); glVertex3d(-0.2, -0.25, 0.0);
    glTexCoord2f(1.0f, 0.0f); glVertex3d(0.2, -0.25, 0.0);
    glTexCoord2f(1.0f, 1.0f); glVertex3d(0.06, 0.22, 0.0);
    glTexCoord2f(0.0f, 1.0f); glVertex3d(-0.06, 0.22, 0.0);
    glEnd();
    glEndList();

    glNewList(upper_arm_list, GL_COMPILE);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glColor3f(0.1, 0.6, 0.1);
    draw_cube(0.1, 0.1, 0.3);
    glEndList();

    glNewList(lower_arm_list, GL_COMPILE);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glColor3f(0.4, 0.1, 0.1);
    draw_cube(0.1, 0.1, 0.3);
    glEndList();

    glNewList(upper_leg_list, GL_COMPILE);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glColor3d(0.5,0.1,0.5);
    draw_cube(0.1, 0.15, 0.3);
    glEndList();

    glNewList(lower_leg_list, GL_COMPILE);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glColor3d(0.1,0.7, 0.3);
    draw_cube(0.1, 0.1, 0.3);
    glEndList();

    glNewList(feet_list, GL_COMPILE);
    glColor3d(1.0, 1.0, 1.0);
    GLfloat headlight_pos[] = {1.0f, 0.0f, 0.0f, 1.0f};
    GLfloat spotlight_pos[] = {-1.0f, 0.0f, 0.0f};
    GLfloat headlight_prop[] = {1.0f, 1.0f, 1.0f, 1.0f};
    glLightfv(GL_LIGHT1, GL_POSITION, headlight_pos);
    glLightfv(GL_LIGHT1, GL_SPECULAR, headlight_prop);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 10.0);
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0);
    glLightfv(GL_LIGHT1,GL_SPOT_DIRECTION,spotlight_pos);

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

    glPushAttrib(GL_LIGHTING_BIT);
    glNewList(head_list, GL_COMPILE);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glColor3f(0.0f, 0.0f, 0.6f);
    //glColorMaterial(GL_FRONT, GL_DIFFUSE);
    draw_cube(0.2,0.2,0.2);
    glEndList();
    glPopAttrib();

    glNewList(mouth_list, GL_COMPILE);
    draw_cube(0.1,0.02,0.02);
    glEndList();

    glNewList(neck_list, GL_COMPILE);
    draw_cube(0.1, 0.1, 0.1);
    glEndList();

    glNewList(torso_list, GL_COMPILE);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    float torso_color[] = {0.5f, 0.4f, 0.3f};
    glColor3fv(torso_color);
    //glMaterialfv(GL_FRONT, GL_DIFFUSE, torso_color);
    draw_cube(0.4, 0.2, 0.5);
    glEndList();

}


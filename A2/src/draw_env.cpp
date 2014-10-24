/*
 * draw_env.cpp
 *
 *  Created on: Oct 23, 2014
 *      Author: dheerendra
 */

#include <iostream>
#include <GL/glew.h>

using namespace std;

#include "draw_cube.hpp"
#include "draw_rectangle.hpp"
#include "texture.hpp"

double color[24] = { 0.4, 0.6, 0.1, 1.0, 0.6, 0.1, 0.6, 1.0, 0.7, 0.8, 0.1, 1.0,
        0.8, 0.1, 0.5, 1.0, 0.8, 0.5, 1.0, 1.0, 0.7, 0.1, 0.6, 1.0 };

void draw_env(){


    glPushMatrix();
    glPushAttrib(GL_CURRENT_BIT);
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glTranslated(0.0, -2.0, 0.0);
    glRotated(90.0, 1.0, 0.0, 0.0);
    for (int i=1; i< 19; i++){
        for (int j = 1; j< 19; j++){
            glPushMatrix();
            glTranslated(i*10-95, j*10-95, 0.0);
            draw_rectangle(10, 10);
            glPopMatrix();
        }
    }
    glBindTexture(GL_TEXTURE_2D, texture[4]);
    for (int i=0; i< 20; i+=19){
        for (int j = 0; j< 20; j++){
            glPushMatrix();
            glTranslated(i*10-95, j*10-95, 0.0);
            draw_rectangle(10, 10);
            glPopMatrix();
        }
    }
    for (int i=0; i< 20; i++){
            for (int j = 0; j< 20; j+=19){
                glPushMatrix();
                glTranslated(i*10-95, j*10-95, 0.0);
                draw_rectangle(10, 10);
                glPopMatrix();
            }
        }
    glPopAttrib();
    glPopMatrix();

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[2]);
    glTranslated(0.0, -2.1, 0.0);
    glRotated(90.0, 1.0, 0.0, 0.0);
    draw_rectangle(1000, 1000);
    glPopMatrix();

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[3]);
    glTranslated(0.0, 50.0f, 0.0);
    glRotated(90.0, 1.0, 0.0, 0.0);
    draw_rectangle(1000, 1000);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.0, 25.0, 500.0f);
    draw_rectangle(1000, 52);
    glPopMatrix();


    glPushMatrix();
    glTranslated(0.0, 25.0, -500.0f);
    draw_rectangle(1000, 52);
    glPopMatrix();

    glPushMatrix();
    glTranslated(500.0, 25.0, 0.0f);
    glRotated(90, 0.0, 1.0, 0.0);
    draw_rectangle(1000, 52);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-500.0, 25.0, 0.0f);
    glRotated(90, 0.0, 1.0, 0.0);
    draw_rectangle(1000, 52);
    glPopMatrix();
}

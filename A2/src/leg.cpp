/*
 * leg.cpp
 *
 *  Created on: Sep 30, 2014
 *      Author: dheerendra
 */

#include<GL/glew.h>

#include "leg.hpp"
#include "draw_cube.hpp"
#include "transform.hpp"
#include "wheel.hpp"

void draw_leg(int type){

    //Leg translation towards back
    glTranslated(0.0, leg_back, 0.0);
    //Upper Leg rotation
    glTranslated(0.0, 0.15, 0.1);
    glRotated(upper_leg, 1.0, 0.0, 0.0);
    glTranslated(0.0, -0.15, -0.1);

    glPushAttrib(GL_CURRENT_BIT);
        glColor4d(1.0,0.0,0.0,1.0);
        draw_cube(0.1, 0.15, 0.3);
    glPopAttrib();
    glPushMatrix();
    //Lower Leg rotation
        glTranslated(0.0, -0.15, -0.07);
        glRotated(lower_leg, 1.0, 0.0, 0.0);
        glTranslated(0.0, 0.15, 0.07);

        glTranslated(0.0, -0.3, 0.0);
        glPushAttrib(GL_CURRENT_BIT);
            glColor4d(0.0,1.0,0.0,1.0);
            draw_cube(0.1,0.1,0.3);

            glPushMatrix();
                if (type){
                    glTranslated(-0.15, 0.0, 0.075);
                }
                else {
                    glTranslated(0.05, 0.0, 0.075);
                }
                glRotated(90, 0.0, 1.0, 0.0);
                glColor3d(0.5, 0.5, 0.5);
                draw_wheel(0.1);
            glPopMatrix();
        glPopAttrib();
        //foot
        glPushMatrix();
            glRotated(lower_leg, 0.0, 1.0, 0.0);
            glTranslated(0.0, -0.15, 0.05);
            draw_cube(0.1, 0.2, 0.02);
        glPopMatrix();
    glPopMatrix();
}



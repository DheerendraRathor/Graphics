/*
 * leg.cpp
 *
 *  Created on: Sep 30, 2014
 *      Author: dheerendra
 */

#include<GL/glew.h>

#include "leg.hpp"
#include "transform.hpp"
#include "display_list.hpp"

void draw_leg(int type){

    //Leg translation towards back
    glTranslated(0.0, leg_back, 0.0);
    //Upper Leg rotation
    glTranslated(0.0, 0.15, 0.1);
    glRotated(upper_leg, 1.0, 0.0, 0.0);
    glTranslated(0.0, 0.0, -0.1);
    if (type){
        glRotated(lLeg1f, 1.0, 0.0, 0.0);
        glRotated(lLeg2f, 0.0, 1.0, 0.0);
        glRotated(lLeg3f, 0.0, 0.0, 1.0);
    }
    else {
        glRotated(rLeg1f, 1.0, 0.0, 0.0);
        glRotated(rLeg2f, 0.0, 1.0, 0.0);
        glRotated(rLeg3f, 0.0, 0.0, 1.0);
    }

    glTranslated(0.0, -0.15, 0.0);


        glCallList(upper_leg_list);
    glPushMatrix();
    //Lower Leg rotation
        glTranslated(0.0, -0.15, -0.07);
        glRotated(lower_leg, 1.0, 0.0, 0.0);
        if (type){
            glRotated(lLegLower1f, 1.0, 0.0, 0.0);
        }
        else glRotated(rLegLower1f, 1.0, 0.0, 0.0);
        glTranslated(0.0, 0.15, 0.07);

        glTranslated(0.0, -0.3, 0.0);

            glCallList(lower_leg_list);

            glPushMatrix();
                if (type){
                    glTranslated(-0.15, 0.0, 0.075);
                }
                else {
                    glTranslated(0.05, 0.0, 0.075);
                }
                glRotated(90, 0.0, 1.0, 0.0);
                glColor3d(0.5, 0.5, 0.5);
                glCallList(leg_wheel_list);
            glPopMatrix();

        //foot
        glPushMatrix();
            glRotated(lower_leg, 0.0, 1.0, 0.0);
            glTranslated(0.0, -0.15, 0.05);
            glCallList(feet_list);
        glPopMatrix();
    glPopMatrix();
}



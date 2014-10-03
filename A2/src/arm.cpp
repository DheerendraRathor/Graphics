/*
 * arm.cpp
 *
 *  Created on: Oct 1, 2014
 *      Author: dheerendra
 */

#include <GL/glew.h>
#include "gl_framework.hpp"
#include "arm.hpp"
#include "transform.hpp"
#include "display_list.hpp"

void draw_arm(int type){


    glTranslated(0.0, arm_front, -1.0*arm_back);

    //Upper Arm rotation
        glTranslated(0.0, 0.15, 0.1);
        glRotated(upper_arm, 1.0, 0.0, 0.0);
        glTranslated(0.0, 0.0, -0.1);
        if(type){
            glRotated(lArm1f, 1.0, 0.0, 0.0);
            glRotated(lArm2f, 0.0, 1.0, 0.0);
            glRotated(lArm3f, 0.0, 0.0, 1.0);
        }
        else {
            glRotated(rArm1f, 1.0, 0.0, 0.0);
            glRotated(rArm2f, 0.0, 1.0, 0.0);
            glRotated(rArm3f, 0.0, 0.0, 1.0);
        }
    glTranslated(0.0, -0.15, 0.0);

    glCallList(upper_arm_list);
    glPushMatrix();

    //lower arm adjustment
    glTranslated(0.0, 0.0,lower_arm_back);
    //Lower arm rotation
   glTranslated(0.0, -0.15, -0.07);
   glRotated(lower_arm, 1.0, 0.0, 0.0);
   if (type){
       glRotated(lArmLower1f, 1.0, 0.0, 0.0);
   }
   else glRotated(rArmLower1f, 1.0, 0.0, 0.0);
   glTranslated(0.0, 0.15, 0.07);
        glTranslated(0.0, -0.3, 0.0);
        glCallList(lower_arm_list);

        if (type){
            glTranslated(-0.15, 0.0, 0.075);
        }
        else {
            glTranslated(0.05, 0.0, 0.075);
        }
        glRotated(90, 0.0, 1.0, 0.0);
        glColor3d(0.5, 0.5, 0.5);
        glCallList(arm_wheel_list);
    glPopMatrix();
}



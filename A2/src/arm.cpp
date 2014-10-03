/*
 * arm.cpp
 *
 *  Created on: Oct 1, 2014
 *      Author: dheerendra
 */

#include <GL/glew.h>
#include "gl_framework.hpp"
#include "arm.hpp"
#include "draw_cube.hpp"
#include "transform.hpp"
#include "wheel.hpp"

void draw_arm(int type){


    glTranslated(0.0, arm_front, -1.0*arm_back);

    //Upper Arm rotation
        glTranslated(0.0, 0.15, 0.1);
        glRotated(upper_arm, 1.0, 0.0, 0.0);
        glTranslated(0.0, -0.15, -0.1);

    draw_cube(0.1,0.1,0.3);
    glPushMatrix();

    //lower arm adjustment
    glTranslated(0.0, 0.0,lower_arm_back);
    //Lower arm rotation
   glTranslated(0.0, -0.15, -0.07);
   glRotated(lower_arm, 1.0, 0.0, 0.0);
   glTranslated(0.0, 0.15, 0.07);
    glPushAttrib(GL_CURRENT_BIT);
        glTranslated(0.0, -0.3, 0.0);
        glColor3d(0.4, 0.1, 0.2);
        draw_cube(0.1, 0.1, 0.3);

        if (type){
            glTranslated(-0.15, 0.0, 0.075);
        }
        else {
            glTranslated(0.05, 0.0, 0.075);
        }
        glRotated(90, 0.0, 1.0, 0.0);
        glColor3d(0.5, 0.5, 0.5);
        draw_wheel(0.2);
    glPopAttrib();
    glPopMatrix();
}



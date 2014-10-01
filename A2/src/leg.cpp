/*
 * leg.cpp
 *
 *  Created on: Sep 30, 2014
 *      Author: dheerendra
 */

#include<GL/glew.h>

#include "leg.hpp"
#include "draw_cube.hpp"

void draw_leg(){
    glPushAttrib(GL_CURRENT_BIT);
        glColor4d(1.0,0.0,0.0,1.0);
        draw_cube(0.1, 0.15, 0.3);
    glPopAttrib();
    glPushMatrix();
        glTranslated(0.0, -0.3, 0.0);
        glPushAttrib(GL_CURRENT_BIT);
            glColor4d(0.0,1.0,0.0,1.0);
            draw_cube(0.1,0.1,0.3);
        glPopAttrib();
        glPushMatrix();
            glTranslated(0.0, -0.15, 0.05);
            draw_cube(0.1, 0.2, 0.02);
        glPopMatrix();
    glPopMatrix();
}



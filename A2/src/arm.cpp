/*
 * arm.cpp
 *
 *  Created on: Oct 1, 2014
 *      Author: dheerendra
 */

#include <GL/glew.h>
#include <iostream>
#include <string>
#include "gl_framework.hpp"
#include "arm.hpp"
#include "draw_cube.hpp"

void draw_arm(){
    draw_cube(0.1,0.1,0.3);
    glPushMatrix();
    glPushAttrib(GL_CURRENT_BIT);
        glTranslated(0.0, -0.3, 0.0);
        glColor3d(0.4, 0.1, 0.2);
        draw_cube(0.1, 0.1, 0.3);
    glPopAttrib();
    glPopMatrix();
}



/*
 * wheel.cpp
 *
 *  Created on: Oct 3, 2014
 *      Author: dheerendra
 */

#include <GL/glew.h>
#include "wheel.hpp"
#include "transform.hpp"

void draw_wheel(double radius){
    GLUquadricObj* quadric = gluNewQuadric();
    gluCylinder(quadric, radius, radius, 0.1, 20, 20);
    glPushAttrib(GL_CURRENT_BIT);
        glColor3d(0.75, 0.75, 0.75);
        gluDisk(quadric, 0.0, radius, 20, 20);
        glPushMatrix();
            glTranslated(0.0, 0.0, 0.1);
            gluDisk(quadric, 0.0, radius, 20, 20);
        glPopMatrix();
    glPopAttrib();
}


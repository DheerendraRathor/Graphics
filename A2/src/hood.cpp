/*
 * hood.cpp
 *
 *  Created on: Oct 2, 2014
 *      Author: dheerendra
 */

#include <GL/glew.h>
#include "draw_rectangle.hpp"
#include "transform.hpp"
#include "hood.hpp"

void draw_hood(){
    //Top Hood
    glPushMatrix();
        glTranslated(0.0, hood_pull, -0.101);

        glBegin(GL_POLYGON);
            glVertex3d(-0.2, -0.25, 0.0);
            glVertex3d(0.2, -0.25, 0.0);
            glVertex3d(0.06, 0.22, 0.0);
            glVertex3d(-0.06, 0.22, 0.0);
        glEnd();
    glPopMatrix();

    //Side hood
    glPushMatrix();
        glTranslated(0.2, 0.5*flaps_pull, 0.0);
            glRotated(flaps_rotate, 0.0, 0.0, 1.0);
        glTranslated(-0.2, -0.5*flaps_pull, 0.0);
        glTranslated(0.1999, flaps_pull, 0.0);
        glRotated(90.0, 0.0, 1.0, 0.0);
        draw_rectangle(0.2, 0.5);
    glPopMatrix();

    //2nd side hood
    glPushMatrix();
    glTranslated(-0.2, 0.5*flaps_pull, 0.0);
         glRotated(-1.0*flaps_rotate, 0.0, 0.0, 1.0);
    glTranslated(0.2, -0.5*flaps_pull, 0.0);
    glTranslated(-0.1999, flaps_pull, 0.0);
    glRotated(90.0, 0.0, 1.0, 0.0);
    draw_rectangle(0.2, 0.5);
    glPopMatrix();
}




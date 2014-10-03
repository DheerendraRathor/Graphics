/*
 * head.cpp
 *
 *  Created on: Oct 1, 2014
 *      Author: dheerendra
 */
#include <GL/glew.h>

#include "gl_framework.hpp"
#include "draw_cube.hpp"
#include "display_list.hpp"

void draw_head(){
    glCallList(neck_list);
    glPushMatrix();
        glTranslated(0.0, 0.15, 0.0);
        glCallList(head_list);
        //eyes
        glPushMatrix();
            glTranslated(-0.04, 0.04, 0.1);
            glPushAttrib(GL_CURRENT_BIT);
            glColor4d(0.3, 0.2, 1.0, 1.0);
            glCallList(eye_list);
            glPopAttrib();
        glPopMatrix();

        glPushMatrix();
            glTranslated(0.04, 0.04, 0.1);
            glPushAttrib(GL_CURRENT_BIT);
            glColor4d(0.3, 0.2, 1.0, 1.0);
            glCallList(eye_list);
            glPopAttrib();
        glPopMatrix();

        //mouth
        glPushMatrix();
            glTranslated(0.0, -0.04, 0.1);
            glPushAttrib(GL_CURRENT_BIT);
            glColor4d(0.6, 0.2, 0.7, 1.0);
            glCallList(mouth_list);
            glPopAttrib();
        glPopMatrix();
    glPopMatrix();
}


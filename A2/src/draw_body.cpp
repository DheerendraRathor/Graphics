#include <iostream>
#include <GL/glew.h>

using namespace std;

#include "draw_cube.hpp"
#include "draw_body.hpp"
#include "leg.hpp"
#include "head.hpp"
#include "arm.hpp"

void draw_body() {
    glPushMatrix();
        glPushAttrib(GL_CURRENT_BIT);
            glColor4d(0.3, 0.1, 0.6, 0.1);
            draw_cube(0.4, 0.2, 0.5);
        glPopAttrib();

        //Adding head
        glPushMatrix();
            glTranslated(0.0, 0.31, 0.0);
            draw_head();
        glPopMatrix();

        //Inserting Right Leg
        glPushMatrix();
            glTranslated(-0.1, -0.41, 0.0);
            draw_leg();
        glPopMatrix();

        //Inserting Left Leg
        glPushMatrix();
            glTranslated(0.1, -0.41, 0.0);
            draw_leg();
            glPushMatrix();
            glPopMatrix();
        glPopMatrix();

        //Inserting left arm
        glPushMatrix();
            glTranslated(0.3,0.1,0.0);
            draw_arm();
        glPopMatrix();

        //Inserting Right Arm
        glPushMatrix();
            glTranslated(-0.3, 0.1, 0.0);
            draw_arm();
        glPopMatrix();


    glPopMatrix();
}

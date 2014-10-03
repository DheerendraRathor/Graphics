#include <iostream>
#include <GL/glew.h>

#include "draw_rectangle.hpp"
using namespace std;

void draw_rectangle(double width, double height) {
    double hw1 = -1.0 * width / 2;
    double hw2 = width / 2;
    double hh1 = -1.0 * height / 2;
    double hh2 = height / 2;
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f); glVertex3d(hw1, hh1, 0.0);
    glTexCoord2f(1.0f, 0.0f); glVertex3d(hw2, hh1, 0.0);
    glTexCoord2f(1.0f, 1.0f); glVertex3d(hw2, hh2, 0.0);
    glTexCoord2f(0.0f, 1.0f); glVertex3d(hw1, hh2, 0.0);
    glEnd();
    glPushAttrib(GL_CURRENT_BIT);
        glColor4d(0.0,0.0,0.0,0.0);
        /*glBegin(GL_LINE_LOOP);
            glVertex3d(hw1, hh1, 0.0);
            glVertex3d(hw2, hh1, 0.0);
            glVertex3d(hw2, hh2, 0.0);
            glVertex3d(hw1, hh2, 0.0);
        glEnd();*/
    glPopAttrib();
}



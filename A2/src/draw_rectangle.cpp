#include <GL/glew.h>
#include <iostream>

#include "draw_rectangle.hpp"

void draw_rectangle(double width, double height) {
    double hw1 = -1.0 * width / 2;
    double hw2 = width / 2;
    double hh1 = -1.0 * height / 2;
    double hh2 = height / 2;

    glBegin(GL_QUADS);

        glTexCoord2d(0.0, 0.0); glVertex3d(hw1, hh1, 0.0);
        glTexCoord2d(1.0, 0.0); glVertex3d(hw2, hh1, 0.0);
        glTexCoord2d(1.0, 1.0); glVertex3d(hw2, hh2, 0.0);
        glTexCoord2d(0.0, 1.0); glVertex3d(hw1, hh2, 0.0);
    glEnd();
}



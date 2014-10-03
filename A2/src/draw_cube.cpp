#include <iostream>
#include <GL/glew.h>

using namespace std;

#include "draw_cube.hpp"
#include "draw_rectangle.hpp"

void draw_cube(double length, double width, double height) {
    glPushMatrix();
        glTranslated(0.0, 0.0, width / 2);
        draw_rectangle(length, height);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0.0, 0.0, -1.0 * width / 2);
        draw_rectangle(length, height);
    glPopMatrix();

    glPushMatrix();
        glTranslated(length / 2, 0.0, 0.0);
        glRotated(90, 0.0, 1.0, 0.0);
        draw_rectangle(width, height);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-1.0 * length / 2, 0.0, 0.0);
        glRotated(90.0, 0.0, 1.0, 0.0);
        draw_rectangle(width, height);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0.0, height / 2, 0.0);
        glRotated(90.0, 1.0, 0.0, 0.0);
        draw_rectangle(length, width);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0.0, -1.0 * height / 2, 0.0);
        glRotated(90.0, 1.0, 0.0, 0.0);
        draw_rectangle(length, width);
    glPopMatrix();
}

void draw_cube(double length, double width, double height, double* color) {
    glPushMatrix();
        glTranslated(0.0, 0.0, width / 2);
        glColor4f(color[0], color[1], color[2], color[3]);
        draw_rectangle(length, height);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0.0, 0.0, -1.0 * width / 2);
        glColor4f(color[4], color[5], color[6], color[7]);
        draw_rectangle(length, height);
    glPopMatrix();

    glPushMatrix();
        glTranslated(length / 2, 0.0, 0.0);
        glRotated(90, 0.0, 1.0, 0.0);
        glColor4f(color[8], color[9], color[10], color[11]);
        draw_rectangle(width, height);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-1.0 * length / 2, 0.0, 0.0);
        glRotated(90.0, 0.0, 1.0, 0.0);
        glColor4f(color[12], color[13], color[14], color[15]);
        draw_rectangle(width, height);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0.0, height / 2, 0.0);
        glRotated(90.0, 1.0, 0.0, 0.0);
        glColor4f(color[16], color[17], color[18], color[19]);
        draw_rectangle(length, width);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0.0, -1.0 * height / 2, 0.0);
        glRotated(90.0, 1.0, 0.0, 0.0);
        glColor4f(color[20], color[21], color[22], color[23]);
        draw_rectangle(length, width);
    glPopMatrix();
}

#ifndef _CUBE_HPP_
#define _CUBE_HPP_

#include "gl_framework.hpp"
void draw_cube(double, double, double);

//In case when color for all faces can be passed as 24 double matrix
void draw_cube(double, double, double, double*);

#endif

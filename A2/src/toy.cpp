/*
 * CS475/CS675 - Computer Graphics
 *  ToyLOGO Assignment Base Code
 *
 * Copyright 2009-2014, Parag Chaudhuri, Department of CSE, IIT Bombay
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <string>

#include "gl_framework.hpp"

#include "draw_body.hpp"
#include "transform.hpp"

std::string filename, progname;
bool file_flag = false;

namespace csX75{
int key_pressed;
}

double color[24] = { 0.4, 0.6, 0.1, 1.0, 0.6, 0.1, 0.6, 1.0, 0.7, 0.8, 0.1, 1.0,
        0.8, 0.1, 0.5, 1.0, 0.8, 0.5, 1.0, 1.0, 0.7, 0.1, 0.6, 1.0 };

double rotate = 1.0;

//GLFW display callback
void renderGL() {
   glRotated(rotate, 1.0, 1.0, 1.0);
    draw_body();
}

//Function to print the command line usage information
void usage(void) {
    std::cerr << "usage: " << progname << " [-f filename]" << std::endl
            << std::endl;
    std::cerr
            << "\t-f\t filename of the file with the ToyLOGO source program\n";
    std::cerr
            << "\t\t If no filename is given then a default drawing is drawn.\n";
    exit(0);
}

int main(int argc, char *argv[]) {
    progname = argv[0];

    //! The pointer to the GLFW window
    GLFWwindow* window;

    //! Setting up the GLFW Error callback
    glfwSetErrorCallback(csX75::error_callback);

    //! Initialize GLFW
    if (!glfwInit())
        return -1;

    int win_width = 512;
    int win_height = 512;

    //! Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(win_width, win_height, "ToyLOGO", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    //! Make the window's context current 
    glfwMakeContextCurrent(window);

    //Keyboard Callback
    glfwSetKeyCallback(window, csX75::key_callback);
    //Framebuffer resize callback
    glfwSetFramebufferSizeCallback(window, csX75::framebuffer_size_callback);

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    glfwGetFramebufferSize(window, &win_width, &win_height);
    csX75::framebuffer_size_callback(window, win_width, win_height);
    //Initialize GL state
    csX75::initGL();
    glEnable(GL_DEPTH_TEST);

    // Loop until the user closes the window
    while (glfwWindowShouldClose(window) == 0) {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        switch (csX75::key_pressed) {
            case 'L':
                legs = 1; csX75::key_pressed = 0;
                break;
            case 'A':
                arms = 1; csX75::key_pressed = 0;
                break;
            case 'F':
                flaps = 1; csX75::key_pressed = 0;
                break;
            default:
                break;
        }

        if (legs && !leg_rotated){
            if (upper_leg >= -180.0)upper_leg -= 1.0;
            if (lower_leg <= 180.0) lower_leg += 1.0;
            if (leg_back >= -0.2 && upper_leg <= -180.0) leg_back -=0.001;
            if (leg_back <= -0.2){
                leg_rotated = 1;
                legs = 0;
            }
        }

        if (arms && !arm_rotated){
            if (arm_close <= 0.05) arm_close += 0.001;
            if (arm_back <= 0.05) arm_back += 0.001;
            if (lower_arm_back <= 0.03) lower_arm_back += 0.001;
            if (upper_arm >= -180.0)upper_arm -= 1.0;
            if (lower_arm <= 180.0) lower_arm += 1.0;
            if (arm_front >= -0.2 && upper_arm <= -180.0) arm_front -=0.001;
            if (arm_front <= -0.2){
                arm_rotated = 1;
                arms = 0;
            }
         }

        if (flaps && !flaps_rotated){
            if (flaps_pull <= 0.45) flaps_pull += 0.05;
            if (hood_pull <= 0.45) hood_pull += 0.05;
            if (flaps_pull >= 0.45){
                if(flaps_rotate <= 17.0) flaps_rotate+= 1.0;
            }
        }

        // Render here
        renderGL();
        //GLUquadricObj* quad_t = gluNewQuadric();

        /*glRotated(0.1, 1.0, 0.0,0.0);
        glColor3d(0.1, 0.2, 0.3);
        gluCylinder(quad_t, 0.5, 0.5, 0.2, 100, 100);
        glColor3d(0.2, 0.3, 0.4);
        gluDisk(quad_t, 0.0, 0.5, 100, 100);*/

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

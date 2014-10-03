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
#include "display_list.hpp"

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
   //glRotated(rotate, 1.0, 1.0, 1.0);
    draw_body();
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
    genDisplayList();
    //std::cerr<<side_flap<<std::endl;

    // Loop until the user closes the window
    while (glfwWindowShouldClose(window) == 0) {



        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //std::cerr<<csX75::key_pressed<<std::endl;
        switch (csX75::key_pressed) {
            case 257:
                std::cerr<<"Transforming command executing..."<<std::endl;
                legs = 1; arms = 1; flaps = 1;
                leg_rotated = (leg_rotated + 1) %2;
                arm_rotated = (arm_rotated+1)% 2;
                flaps_rotated = (flaps_rotated + 1)%2;
                break;
            case 'L':
                std::cerr<<'L'<<std::endl;
                legs = 1;
                leg_rotated = (leg_rotated + 1) %2;
                break;
            case 'A':
                std::cerr<<'A'<<std::endl;
                arms = 1;
                arm_rotated = (arm_rotated+1)% 2;
                break;
            case 'F':
                std::cerr<<'F'<<std::endl;
                flaps = 1;
                flaps_rotated = (flaps_rotated + 1)%2;
                break;
            case 'T':
                selected = "torso";
                break;
            case 'N':
                selected = "neck";
                break;
            case 'Q':
                selected = "lArm";
                break;
            case 'Z':
                selected = "rArm";
                break;
            case 'W':
                selected = "lArmLower";
                break;
            case 'X':
                selected = "rArmLower";
                break;
            case 'I':
                selected = "lLeg";
                break;
            case 'M':
                selected = "rLeg";
                break;
            case 'U':
                selected = "lLegLower";
                break;
            case 'Y':
                selected = "rLegLower";
                break;
            case 44:
                if (selected == "torso") torso3f += rotation;
                else if (selected == "neck") neck3f += rotation;
                else if (selected == "lArm") lArm3f += rotation;
                else if (selected == "rArm") rArm3f += rotation;
                else if (selected == "lLeg") lLeg3f += rotation;
                else if (selected == "rLeg") rLeg3f += rotation;

                break;
            case 46:
                if (selected == "torso") torso3f -= rotation;
                else if (selected == "neck") neck3f -= rotation;
                else if (selected == "lArm") lArm3f -= rotation;
                else if (selected == "rArm") rArm3f -= rotation;
                else if (selected == "lLeg") lLeg3f -= rotation;
                else if (selected == "rLeg") rLeg3f -= rotation;
                break;
            case 263:
                if (selected == "torso") torso2f -= rotation;
                else if (selected == "neck") neck2f -= rotation;
                else if (selected == "lArm") lArm2f -= rotation;
                else if (selected == "rArm") rArm2f -= rotation;
                else if (selected == "lLeg") lLeg2f -= rotation;
                else if (selected == "rLeg") rLeg2f -= rotation;
                break;
            case 262:
                if (selected == "torso") torso2f += rotation;
                else if (selected == "neck") neck2f += rotation;
                else if (selected == "lArm") lArm2f += rotation;
                else if (selected == "rArm") rArm2f += rotation;
                else if (selected == "lLeg") lLeg2f += rotation;
                else if (selected == "rLeg") rLeg2f += rotation;
                break;
            case 264:
                if (selected == "torso") torso1f -= rotation;
                else if (selected == "neck") neck1f -= rotation;
                else if (selected == "lArm") lArm1f -= rotation;
                else if (selected == "rArm") rArm1f -= rotation;
                else if (selected == "lLeg") lLeg1f -= rotation;
                else if (selected == "rLeg") rLeg1f -= rotation;
                else if (selected == "lArmLower") lArmLower1f -= rotation;
                else if (selected == "rArmLower") rArmLower1f -= rotation;
                else if (selected == "lLegLower") lLegLower1f -= rotation;
                else if (selected == "rLegLower") rLegLower1f -= rotation;
                break;
            case 265:
                if (selected == "torso") torso1f += rotation;
                else if (selected == "neck") neck1f += rotation;
                else if (selected == "lArm") lArm1f += rotation;
                else if (selected == "rArm") rArm1f += rotation;
                else if (selected == "lLeg") lLeg1f += rotation;
                else if (selected == "rLeg") rLeg1f += rotation;
                else if (selected == "lArmLower") lArmLower1f += rotation;
                else if (selected == "rArmLower") rArmLower1f += rotation;
                else if (selected == "lLegLower") lLegLower1f += rotation;
                else if (selected == "rLegLower") rLegLower1f += rotation;
                break;
            case 'R':
                rotation = 1.0;
                torso1f = 0.0;
                torso2f = 0.0;
                torso3f = 0.0;
                neck1f = 0.0;
                neck2f = 0.0;
                neck3f = 0.0;
                lArm1f = 0.0;
                lArm2f = 0.0;
                lArm3f = 0.0;
                rArm1f = 0.0;
                rArm2f = 0.0;
                rArm3f = 0.0;
                lLeg1f = 0.0;
                lLeg2f = 0.0;
                lLeg3f = 0.0;
                rLeg1f = 0.0;
                rLeg2f = 0.0;
                rLeg3f = 0.0;
                lArmLower1f = 0.0;
                rArmLower1f = 0.0;
                lLegLower1f = 0.0;
                rLegLower1f = 0.0;
                selected = "";
                break;

            default:
                break;
        }
        if (csX75::key_pressed - 48 < 10 && (csX75::key_pressed - 48 >0)){
            rotation = csX75::key_pressed - 48;
        }
        csX75::key_pressed = 0;
        //std::cerr<<legs<<std::endl;
        //std::cerr<<"upper_leg::"<<leg_back<<std::endl;
        if (legs && leg_rotated){
            if (upper_leg >= -180.0)upper_leg -= 1.0;
            if (lower_leg <= 180.0) lower_leg += 1.0;
            if (leg_back >= -0.2 && upper_leg <= -180.0) leg_back -=0.001;
            if (leg_back <= -0.2){
                legs = 0;
            }
        }

        else if (legs){
            if (upper_leg < 0.0 && leg_back >= 0.0)upper_leg += 1.0;
            if (lower_leg > 0.0 && leg_back >= 0.0) lower_leg -= 1.0;
            if (leg_back < 0.0) leg_back +=0.001;
            if (upper_leg >= 0.0){
                legs = 0;
            }
        }

        //Arms animation to car
        if (arms && arm_rotated){
            if (arm_close <= 0.05) arm_close += 0.001;
            if (arm_back <= 0.05) arm_back += 0.001;
            if (lower_arm_back <= 0.03) lower_arm_back += 0.001;
            if (upper_arm >= -180.0)upper_arm -= 1.0;
            if (lower_arm <= 180.0) lower_arm += 1.0;
            if (arm_front >= -0.2 && upper_arm <= -180.0) arm_front -=0.001;
            if (arm_front <= -0.2){
                arms = 0;
            }
         }

        //Arms animation to autobot
        else if (arms){
            if (arm_close > 0.0 && arm_front >= 0.0) arm_close -= 0.001;
            if (arm_back > 0.0 && arm_front >= 0.0) arm_back -= 0.001;
            if (lower_arm_back > 0.0 && arm_front >= 0.0) lower_arm_back -= 0.001;
            if (upper_arm < 0.0 && arm_front >= 0.0)upper_arm += 1.0;
            if (lower_arm > 0.0 && arm_front >= 0.0) lower_arm -= 1.0;
            if (arm_front < 0.0) arm_front +=0.001;
            if (upper_arm >= 0.0){
                arms = 0;
            }
        }

        if (flaps && flaps_rotated){
            if (flaps_pull <= 0.45) flaps_pull += 0.05;
            if (hood_pull <= 0.45) hood_pull += 0.05;
            if (flaps_pull >= 0.45){
                if(flaps_rotate <= 17.0) flaps_rotate+= 1.0;
            }
        }

        else if(flaps){
            if (flaps_pull > 0.0 && flaps_rotate <= 0.0) flaps_pull -= 0.05;
            if (hood_pull > 0.0 && flaps_rotate <= 0.0) hood_pull -= 0.05;
            if (flaps_pull >= 0.45){
                if(flaps_rotate > 0.0) flaps_rotate-= 1.0;
            }
        }

        // Render here
        renderGL();

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

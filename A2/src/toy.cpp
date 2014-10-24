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
#include <cmath>

#include "gl_framework.hpp"

#include "draw_cube.hpp"
#include "draw_body.hpp"
#include "transform.hpp"
#include "display_list.hpp"
#include "texture.hpp"
#include "draw_env.hpp"

#define PI 3.14159265

std::string filename, progname;
bool file_flag = false;

namespace csX75{
int key_pressed;
}


double rotate = 1.0;
double angle = 0.0;
double x = 0.0;
double z = 0.0;

//GLFW display callback
void renderGL() {

    GLfloat light_pos[] = {car_x + 0.155*sin(turned*PI/180), -1.05f, car_z - 0.155*cos(turned*PI/180),1.0f};
    GLfloat light_dir[] = {car_x + 2*sin(turned*PI/180), -1.7f, car_z - 2*cos(turned*PI/180)};
    GLfloat diffuse_light[] = {0.7f, 0.7f, 0.7f, 1.0f};
    glLightfv(GL_LIGHT2, GL_POSITION, light_pos);
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, light_dir);
    glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 40.0);
    glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 100.0f);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuse_light);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();               // Reset The Projection Matrix

    gluPerspective(50,1, 0.1, 1000);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    switch(camera_setup){
    case 0:
        gluLookAt(
                    100.0f, 0.0f, 100.0f,
                    0.0f, 0.0f, 0.0f,
                    0.0f, 1.0f, 0.0f
            );
        break;
    case 1:
        gluLookAt(
                car_x, top_cam, car_z,
                car_x, 0.0f, car_z,
                1.0f, 10.0f, 0.0f
        );
        break;
    case 2:
        gluLookAt(
                car_x - 4*sin(turned*PI/180), 0.0f, car_z + 4*cos(turned*PI/180),
                car_x + sin(turned*PI/180), 0.0f, car_z - cos(turned*PI/180),
                0.0f, 1.0f, 0.0f
        );
        break;
    case 3:
        gluLookAt(
                car_x + 0.155*sin(turned*PI/180), -1.05f, car_z - 0.155*cos(turned*PI/180),
                car_x + 2*sin(turned*PI/180), -1.2f, car_z - 2*cos(turned*PI/180),
                0.0f, 1.0f, 0.0f
        );
    break;
    }


    draw_env();

    draw_body();
    rotate++;


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
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glShadeModel(GL_SMOOTH);
    GLfloat  ambientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);


    float light0_position[] = { 10, 10.0, 10.0f , 1.0f};
    float light0_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);

    float light1_position[] = { 10, 10.0, 10.0f , 1.0f};
    float light1_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };

    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
    glLightfv(GL_LIGHT1, GL_POSITION, light1_position);

    /*GLfloat LightAmbient1[] = { 0.5f, 0.5f, 0.5f, 1.0f };
    GLfloat LightDiffuse1[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat position1[] =  {0.05, 0.075, 0.08, 1.0}; //Add pos_x to x coordinate and pos_z to z coordinate
    GLfloat spotDir1[] = {0.0, 0.0, -1.0};   //Rotate wrt rotate_y
    glLightfv(GL_LIGHT2, GL_AMBIENT, LightAmbient1);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, LightDiffuse1);
    glLightfv(GL_LIGHT2, GL_POSITION, position1);
    glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 10.0);
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spotDir1);
    glEnable(GL_LIGHT2);*/


    //Pre car formation
    legs = 1; arms = 1; flaps = 1; body = 1;
    leg_rotated = (leg_rotated + 1) %2;
    arm_rotated = (arm_rotated+1)% 2;
    flaps_rotated = (flaps_rotated + 1)%2;
    body_rotated = (body_rotated + 1) %2;


    //Loading Textures
    loadGLTextures();

    //Calling display list
    genDisplayList();
    //std::cerr<<side_flap<<std::endl;

    // Loop until the user closes the window
    while (glfwWindowShouldClose(window) == 0) {



        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        switch (csX75::key_pressed) {
            case 257:
                legs = 1; arms = 1; flaps = 1; body = 1;
                leg_rotated = (leg_rotated + 1) %2;
                arm_rotated = (arm_rotated+1)% 2;
                flaps_rotated = (flaps_rotated + 1)%2;
                body_rotated = (body_rotated + 1) %2;
                break;
            case 265:
                if (speed < 2000) speed += 200;
                break;
            case 264:
                if (speed > -500) speed -= 200;
                break;
            case 'C':
                camera_setup = (camera_setup + 1) % 4;
                break;
            case 263:
                if (speed) {
                    turned = turned - 1;
                }
                if (leg_wheel_turn < 30){
                    leg_wheel_turn += 10;
                }
                break;
            case 262:
                if (speed) {
                    turned = turned + 1;
                }
                if (leg_wheel_turn > -30){
                    leg_wheel_turn -= 10;
                }
                break;
            case 'Q':
                l0_enable = (l0_enable + 1) % 2;
                break;
            case 'W':
                l1_enable = (l1_enable + 1) % 2;
                break;
            case 'M':
                if(camera_setup == 1)top_cam += 2;
                break;
            case 'N':
                if(camera_setup == 1)top_cam -= 2;
                break;
            case 'H':
                headlight = (headlight + 1) % 2;
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

        if (body && body_rotated){
            if(main_rotation <= 90.0) {
                main_rotation += 1.0;
                if (touching_ground > -1.0){
                    touching_ground -= 0.01;
                }
            }
            if (main_rotation >= 90.0){
                body = 0;
                while (touching_ground >-1.0){
                    touching_ground -= 0.01;
                }
            }
        }
        else if (body){
            if (main_rotation > 0.0) {
                main_rotation -= 1.0;
                if (touching_ground < 0.0){
                    touching_ground += 0.01;
                }
            }
            if (main_rotation <= 0.0){
                body =0;
                while (touching_ground <= 0.0){
                    touching_ground+= 0.01;
                }
            }
        }

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

        //car running
        if (speed!=0){
            if (car_z <= 98 && car_z >= -98 && car_x <= 98 && car_x >= -98){
             car_z = car_z - speed*cos(turned*PI/180)/10000;
             car_x = car_x + speed*sin(turned* PI/180)/10000;
            }
            else {
                if (car_z < 0) car_z += 3;
                if (car_z > 0) car_z -= 3;
                if (car_x < 0) car_x += 3;
                if (car_x > 0) car_x -= 3;
                speed = 0;

            }

            if (speed > 0){
                speed = speed -5;
            }

            if (speed < 0)
            {
                speed  = speed + 5;
            }

        }
        if (leg_wheel_turn != 0){
            if (leg_wheel_turn > 0){
                leg_wheel_turn -= 0.5;
            }
            else leg_wheel_turn += 0.5;
        }

        if (l0_enable){
            glEnable(GL_LIGHT0);
        }
        else glDisable(GL_LIGHT0);

        if (l1_enable){
            glEnable(GL_LIGHT1);
        }
        else glDisable(GL_LIGHT1);

        if (headlight){
            glEnable(GL_LIGHT2);
        }
        else glDisable(GL_LIGHT2);

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

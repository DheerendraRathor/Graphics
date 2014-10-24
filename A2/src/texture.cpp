/*
 * texture.cpp
 *
 *  Created on: Oct 3, 2014
 *      Author: dheerendra
 */

#include <SOIL.h>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <GL/glew.h>
#include "texture.hpp"

using namespace std;

unsigned int texture[100];
int texture_count = 5;



void loadGLTextures() {
    char a[100][100];

        strcpy(a[0],"texture_image/metal.jpg");
        strcpy(a[1],"texture_image/grass.jpg");
        strcpy(a[2],"texture_image/water.jpg");
        strcpy(a[3],"texture_image/sky.jpg");
        strcpy(a[4],"texture_image/sand.jpg");

        for (int i = 0; i < texture_count; i++)
        {
            texture[i]=SOIL_load_OGL_texture(
                a[i],
                 SOIL_LOAD_AUTO,
                SOIL_CREATE_NEW_ID,
                SOIL_FLAG_INVERT_Y
            );
            if(texture[i] == 0)
            {
                cout<<"Failed to load "<<a[i]<<" : "<<SOIL_last_result()<<"\n";
            }
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        }

        glEnable(GL_TEXTURE_2D);
};



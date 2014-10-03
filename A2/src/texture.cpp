/*
 * texture.cpp
 *
 *  Created on: Oct 3, 2014
 *      Author: dheerendra
 */

#include <stdio.h>      // Header file for standard file i/o.
#include <stdlib.h>     // Header file for malloc/free.
#include <GL/glew.h>
#include "texture.hpp"

struct Image{
    unsigned long sizeX;
    unsigned long sizeY;
    char *data;
};

unsigned int texture_torso[8];

typedef struct Image Image;

int ImageLoad(char *filename, Image *image) {
    FILE *file;
    unsigned long size;                 // size of the image in bytes.
    unsigned long i;                    // standard counter.
    unsigned short int planes;          // number of planes in image (must be 1)
    unsigned short int bpp;             // number of bits per pixel (must be 24)
    char temp;                          // temporary color storage for bgr-rgb conversion.

    // make sure the file is there.
    if ((file = fopen(filename, "rb"))==NULL)
    {
    printf("File Not Found : %s\n",filename);
    return 0;
    }

    // seek through the bmp header, up to the width/height:
    fseek(file, 18, SEEK_CUR);

    image->sizeX = 256;
    image->sizeY = 256;

    // read the width
    /*if ((i = fread(&image->sizeX, 4, 1, file)) != 1) {
    printf("Error reading width from %s.\n", filename);
    return 0;
    }
    printf("Width of %s: %lu\n", filename, image->sizeX);

    // read the height
    if ((i = fread(&image->sizeY, 4, 1, file)) != 1) {
    printf("Error reading height from %s.\n", filename);
    return 0;
    }
    printf("Height of %s: %lu\n", filename, image->sizeY);*/

    // calculate the size (assuming 24 bits or 3 bytes per pixel).
    size = image->sizeX * image->sizeY * 3;

    /*// read the planes
    if ((fread(&planes, 2, 1, file)) != 1) {
    printf("Error reading planes from %s.\n", filename);
    return 0;
    }
    if (planes != 1) {
    printf("Planes from %s is not 1: %u\n", filename, planes);
    return 0;
    }*/

    // read the bpp
   /* if ((i = fread(&bpp, 2, 1, file)) != 1) {
    printf("Error reading bpp from %s.\n", filename);
    return 0;
    }
    if (bpp != 24) {
    printf("Bpp from %s is not 24: %u\n", filename, bpp);
    return 0;
    }*/

    // seek past the rest of the bitmap header.
    fseek(file, 24, SEEK_CUR);

    // read the data.
    image->data = (char *) malloc(size);
    if (image->data == NULL) {
    printf("Error allocating memory for color-corrected image data\n");
    return 0;
    }

    if ((i = fread(image->data, size, 1, file)) != 1) {
    printf("Error reading image data from %s.\n", filename);
    return 0;
    }

    for (i=0;i<size;i+=3) { // reverse all of the colors. (bgr -> rgb)
    temp = image->data[i];
    image->data[i] = image->data[i+2];
    image->data[i+2] = temp;
    }

    // we're done.
    return 1;
}

void loadGLTextures() {
    // Load Texture
    Image *image1;
    Image *image2;
    Image *image3;
    Image *image4;
    Image *image5;
    Image *image6;
    Image *image7;
    Image *image8;

    // allocate space for texture
   image1 = (Image *) malloc(sizeof(Image));
    image2 = (Image*) malloc(sizeof(Image));
    image3 = (Image*) malloc(sizeof(Image));
    image4 = (Image*) malloc(sizeof(Image));
    image5 = (Image*) malloc(sizeof(Image));
    image6 = (Image*) malloc(sizeof(Image));
    image7 = (Image*) malloc(sizeof(Image));
    image8 = (Image*) malloc(sizeof(Image));
    if (
            image1 == NULL ||
            image2 == NULL ||
            image3 == NULL ||
            image4 == NULL ||
            image5 == NULL ||
            image6 == NULL ||
            image7 == NULL ||
            image8 == NULL
        ) {
    printf("Error allocating space for image");
    exit(0);
    }

    if (
            !ImageLoad("texture_image/torso1.bmp", image1) ||
             !ImageLoad("texture_image/torso2.bmp", image2) ||
            !ImageLoad("texture_image/torso3.bmp", image3) ||
            !ImageLoad("texture_image/torso4.bmp", image4) ||
            !ImageLoad("texture_image/torso5.bmp", image5) ||
            !ImageLoad("texture_image/torso6.bmp", image6) ||
            !ImageLoad("texture_image/torso7.bmp", image7) ||
            !ImageLoad("texture_image/torso8.bmp", image8)
        ){
        exit(1);
    }




    glGenTextures(1, &texture_torso[0]);
    glBindTexture(GL_TEXTURE_2D, texture_torso[0]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image1->sizeX, image1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image1->data);

    glGenTextures(1, &texture_torso[1]);
    glBindTexture(GL_TEXTURE_2D, texture_torso[1]);   // 2d texture (x and y size)
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image2->sizeX, image2->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image2->data);


    glGenTextures(1, &texture_torso[2]);
    glBindTexture(GL_TEXTURE_2D, texture_torso[2]);   // 2d texture (x and y size)
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image3->sizeX, image3->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image3->data);

    glGenTextures(1, &texture_torso[3]);
    glBindTexture(GL_TEXTURE_2D, texture_torso[3]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image4->sizeX, image4->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image4->data);

    glGenTextures(1, &texture_torso[4]);
    glBindTexture(GL_TEXTURE_2D, texture_torso[4]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image5->sizeX, image5->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image5->data);

    glGenTextures(1, &texture_torso[5]);
    glBindTexture(GL_TEXTURE_2D, texture_torso[5]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image6->sizeX, image6->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image6->data);

    glGenTextures(1, &texture_torso[6]);
    glBindTexture(GL_TEXTURE_2D, texture_torso[6]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image7->sizeX, image7->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image7->data);

    glGenTextures(1, &texture_torso[7]);
    glBindTexture(GL_TEXTURE_2D, texture_torso[7]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image7->sizeX, image7->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image7->data);
};



/*
 * texture.hpp
 *
 *  Created on: Oct 3, 2014
 *      Author: dheerendra
 */

#ifndef TEXTURE_HPP_
#define TEXTURE_HPP_

struct Image;

extern unsigned int texture_torso[8];

int ImageLoad(char*, Image*);
void loadGLTextures();


#endif /* TEXTURE_HPP_ */

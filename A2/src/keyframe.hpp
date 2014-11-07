/*
 * keyframe.hpp
 *
 *  Created on: Nov 7, 2014
 *      Author: dheerendra
 */

#ifndef KEYFRAME_HPP_
#define KEYFRAME_HPP_

extern int fps;

void record_key_frame();
void playback_prepare();
void playback();
void capture_frame(int, int, int);


#endif /* KEYFRAME_HPP_ */

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


#include "render_drawing.hpp"
#include <stdlib.h>
#include <time.h>
void triline(turtle_t &turt, double length)
{
   if (length <= 0.01)
   {
      turt.forward(length);
   }
   else
   {
     double newlength = length/3.0;
     triline(turt, newlength);
     turt.turn_left(60);
     triline(turt, newlength);
     turt.turn_right(120);
     triline(turt, newlength);
     turt.turn_left(60);
     triline(turt, newlength);
   }
}

//Drawing a Koch Snowflake
void koch(turtle_t &turt, double x)
{
   turt.reset();
   turt.clear();
   turt.set_pos(-0.3, 0.5);
   turt.turn_right(30);

   for (int i = 0; i<3; i++)
     {
       triline(turt, x);
       turt.turn_right(120);
     }
}

void square_help(turtle_t &turt, int n, double x)
{
	if (n == 0) return;
	for (int i = 0; i< 4 ;i++) {
		turt.turn_left(45);
		turt.forward(x);
		turt.turn_left(45);
		glPushAttrib(GL_CURRENT_BIT);
		glColor3i(rand()%2147483647 +1,rand()%2147483647+1 ,rand() %2147483647+1);	
		square_help(turt,n-1, x/2.2);
		glPopAttrib();
		turt.turn_right(180);
	}

//	getchar();
//	turt.turn_left(45);
//	turt.forward(x);
//	turt.turn_right(135);
}


void square(turtle_t &turt, int n, double x)
{
	srand(time(NULL));
	turt.reset();
	turt.clear();
	turt.turn_left(90);
	turt.backward_move(0.5);
	square_help(turt, n, x);
}
void rg(turtle_t &turt, int st, double ln);
void gl(turtle_t &turt, int st, double ln);

void rg(turtle_t &turt, int st, double ln)
{
	glPushAttrib(GL_CURRENT_BIT);
		glColor3i(rand()%2147483647 +1,rand()%2147483647+1 ,rand() %2147483647+1);	
	st--;
	ln = ln/3;
	if (st >0){
		rg(turt, st, ln);
		turt.turn_right(60);
		gl(turt, st, ln);
		turt.turn_right(120);
		gl(turt, st, ln);
		turt.turn_left(60);
		rg(turt, st, ln);
		turt.turn_left(120);
		rg(turt, st, ln);
		rg(turt, st, ln);
		turt.turn_left(60);
		gl(turt, st, ln);
		turt.turn_right(60);
	}
	if (st == 0){
		turt.forward(ln);
		turt.turn_right(60);
		turt.forward(ln);
		turt.turn_right(120);
		turt.forward(ln);
		turt.turn_left(60);
		turt.forward(ln);
		turt.turn_left(120);
		turt.forward(ln);
		turt.forward(ln);
		turt.turn_left(60);
		turt.forward(ln);
		turt.turn_right(60);
	}
glPopAttrib();
}
		
void gl(turtle_t &turt, int st, double ln)
{
	glPushAttrib(GL_CURRENT_BIT);
		glColor3i(rand()%2147483647 +1,rand()%2147483647+1 ,rand() %2147483647+1);	
	st--;
	ln = ln/3;
	if (st >0){
		turt.turn_left(60);
		rg(turt, st, ln);
		turt.turn_right(60);
		gl(turt, st, ln);
		gl(turt, st, ln);
		turt.turn_right(120);
		gl(turt, st, ln);
		turt.turn_right(60);
		rg(turt, st, ln);
		turt.turn_left(120);
		rg(turt, st, ln);
		turt.turn_left(60);
		gl(turt, st, ln);
	}
	if (st == 0){
		turt.turn_left(60);
		turt.forward(ln);
		turt.turn_right(60);
		turt.forward(ln);
		turt.forward(ln);
		turt.turn_right(120);
		turt.forward(ln);
		turt.turn_right(60);
		turt.forward(ln);
		turt.turn_left(120);
		turt.forward(ln);
		turt.turn_left(60);
		turt.forward(ln);
	}
glPopAttrib();
}

void space_fill(turtle_t &turt, int level, double x)
{
	srand(time(NULL));
	turt.clear();
	turt.reset();
	turt.backward_move(0.5);
	turt.turn_left(90);
	turt.forward_move(0.5);
	turt.turn_right(90);
	gl(turt, level, x);
}
void render_drawing(turtle_t &turt)
{
 // koch(turt, 1.0);
//square(turt, 6, 0.5);
	space_fill(turt, 4, 2.5);
}

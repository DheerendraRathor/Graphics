/*
 * hood.cpp
 *
 *  Created on: Oct 2, 2014
 *      Author: dheerendra
 */

#include <GL/glew.h>
#include "transform.hpp"
#include "hood.hpp"
#include "display_list.hpp"

void draw_hood(){
    //Top Hood
    glPushMatrix();
        glTranslated(0.0, hood_pull, -0.101);
        glCallList(hood_list);
    glPopMatrix();

    //Side hood
    glPushMatrix();
        glTranslated(0.2, 0.5*flaps_pull, 0.0);
            glRotated(flaps_rotate, 0.0, 0.0, 1.0);
        glTranslated(-0.2, -0.5*flaps_pull, 0.0);
        glTranslated(0.1999, flaps_pull, 0.0);
        glRotated(90.0, 0.0, 1.0, 0.0);
        glCallList(side_flap_list);
    glPopMatrix();

    //2nd side hood
    glPushMatrix();
        glTranslated(-0.2, 0.5*flaps_pull, 0.0);
        glRotated(-1.0*flaps_rotate, 0.0, 0.0, 1.0);
        glTranslated(0.2, -0.5*flaps_pull, 0.0);
        glTranslated(-0.1999, flaps_pull, 0.0);
        glRotated(90.0, 0.0, 1.0, 0.0);
        glCallList(side_flap_list);
    glPopMatrix();
}




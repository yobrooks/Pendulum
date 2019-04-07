#ifndef DRAWROOM_CPP
#define DRAWROOM_CPP

#include "openGl.h"
#include "prototypes.h"
#include "globals.h"
#include <iostream>


void defineWallsText()
{
	//ceiling
	
	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glPushMatrix();
	glBegin(GL_POLYGON);
		glTexCoord2d(0.0, 0.0); glVertex3d(-15.0, -15.0, 4.0);
		glTexCoord2d(1.0, 0.0); glVertex3d(-15.0, 15.0, 4.0);
		glTexCoord2d(1.0, 1.0); glVertex3d(15.0, 15.0, 4.0);
		glTexCoord2d(0.0, 1.0); glVertex3d(15.0, -15.0, 4.0);
	glEnd();	
	glPopMatrix();

	//floor
	 glBindTexture(GL_TEXTURE_2D, textures[1]);
	glPushMatrix();
	glBegin(GL_POLYGON);
                glTexCoord2d(0.0, 0.0); glVertex3d(-15.0, -15.0, -6.0);
                glTexCoord2d(1.0, 0.0); glVertex3d(-15.0, 15.0, -6.0);
                glTexCoord2d(1.0, 1.0); glVertex3d(15.0,  15.0, -6.0);
                glTexCoord2d(0.0, 1.0); glVertex3d(15.0, -15.0, -6.0);
	glEnd();
	glPopMatrix();

	//front face
	 glBindTexture(GL_TEXTURE_2D, textures[2]);
	glPushMatrix();
	glBegin(GL_POLYGON);
		glTexCoord2d(0.0, 0.0); glVertex3d(15.0, -15.0, 4.0);
		glTexCoord2d(1.0, 0.0); glVertex3d(15.0, 15.0, 4.0);
		glTexCoord2d(1.0, 1.0); glVertex3d(15.0, 15.0, -6.0);
		glTexCoord2d(0.0, 1.0); glVertex3d(15.0, -15.0, -6.0);
	glEnd();
	glPopMatrix();

	//back side
	 glBindTexture(GL_TEXTURE_2D, textures[3]);
       	glPushMatrix();
	 glBegin(GL_POLYGON);
            		glTexCoord2d(0.0, 0.0);	   glVertex3d(-15.0, -15.0, -6.0);
                	glTexCoord2d(1.0, 0.0);    glVertex3d(-15.0, 15.0, -6.0);
                	glTexCoord2d(1.0, 1.0);	   glVertex3d(-15.0, 15.0, 4.0);
                	glTexCoord2d(0.0, 1.0);    glVertex3d(-15.0, -15.0, 4.0);
        glEnd();
	glPopMatrix();
	

	//right side
	 glBindTexture(GL_TEXTURE_2D, textures[4]);
    	glPushMatrix();
	    glBegin(GL_POLYGON);
               glTexCoord2d(0.0, 0.0); glVertex3d(-15.0, 15.0, 4.0);
               glTexCoord2d(1.0, 0.0); glVertex3d(-15.0, 15.0, -6.0);
               glTexCoord2d(1.0, 1.0); glVertex3d(15.0, 15.0, -6.0);
               glTexCoord2d(0.0, 1.0); glVertex3d(15.0, 15.0, 4.0);
        glEnd();
	glPopMatrix();
	//left side
	 glBindTexture(GL_TEXTURE_2D, textures[5]);
	glPushMatrix();
        glBegin(GL_POLYGON);
               glTexCoord2d(0.0, 0.0);  glVertex3d(-15.0, -15.0, -6.0);
               glTexCoord2d(1.0, 0.0); glVertex3d(-15.0, -15.0, 4.0);
               glTexCoord2d(1.0, 1.0);  glVertex3d(15.0, -15.0, 4.0);
               glTexCoord2d(0.0, 1.0); glVertex3d(15.0, -15.0, -6.0);
        glEnd();
	glPopMatrix();
}

void drawRoomColor()
{
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
		glVertex3d(-15.0, -15.0, 4.0);
		glVertex3d(-15.0, 15.0, 4.0);
		glVertex3d(15.0, 15.0, 4.0);
		glVertex3d(15.0, -15.0, 4.0);
	glEnd();	


	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
		glVertex3d(-15.0, -15.0, -6.0);
		glVertex3d(-15.0, 15.0,-6.0);
		glVertex3d(15.0, 15.0, -6.0);
		glVertex3d(15.0,-15.0, -6.0);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
		glVertex3d(15.0, -15.0, 4.0);
		glVertex3d(15.0, 15.0, 4.0);
		glVertex3d(15.0, 15.0, -6.0);
		glVertex3d(15.0, -15.0, -6.0);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);
        glBegin(GL_POLYGON);
                glVertex3d(-15.0, -15.0, -6.0);
                glVertex3d(-15.0, 15.0, -6.0);
                glVertex3d(-15.0, 15.0, 4.0);
                glVertex3d(-15.0, -15.0, 4.0);
        glEnd();


	glColor3f(1.0, 0.0, 1.0);
        glBegin(GL_POLYGON);
                glVertex3d(-15.0, 15.0, 4.0);
                glVertex3d(-15.0, 15.0, -6.0);
                glVertex3d(15.0, 15.0, -6.0);
                glVertex3d(15.0, 15.0, 4.0);
        glEnd();

	glColor3f(0.0, 1.0, 1.0);
        glBegin(GL_POLYGON);
                glVertex3d(-15.0, -15.0, -6.0);
                glVertex3d(-15.0, -15.0, 4.0);
                glVertex3d(15.0, -15.0, 4.0);
                glVertex3d(15.0, -15.0, -6.0);
        glEnd();


}
#endif

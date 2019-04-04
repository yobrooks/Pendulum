#include "openGl.h"
#include "prototypes.h"
#include "globals.h"
#include <iostream>


void drawLeg()
{
	glColor3f(0.3, 0.2, 0.0);
	glScalef(0.5, 0.5, 3.0);
	glutWireCube(1.0);
}

void drawTable()
{
	//draw base of table
	glPushMatrix();
	glScalef(5.0, 10.0, 1.0);
	glTranslatef(-0.5, 0.0, -3.5);
	glColor3f(0.3, 0.2, 0.0);
	glutWireCube(1.0);
	glPopMatrix();



//draw four legs
 glPushMatrix();
	glTranslatef(-1.0, 3.0, -5.5);
	drawLeg();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.0, -4.0, -5.5);
	drawLeg();
	glPopMatrix();

	glPushMatrix();	
	glTranslatef(-6.0, -4.0, -5.5);
	drawLeg();
	glPopMatrix();

	glPushMatrix();
        glTranslatef(-6.0, 3.0, -5.5);
        drawLeg();
        glPopMatrix();


		
}

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

void drawExtras()
{
	//TODO: draw dj booth and place to put Studio 54 sign 
}

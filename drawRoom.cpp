#include "openGl.h"
#include "prototypes.h"
#include "globals.h"
#include <iostream>
#include "Texture.h"

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

void defineWalls()
{
	//ceiling?
	Texture tex1("./textures/wall 6.jpg");
//	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
		glTexCoord2d(0.0, 0.0); glVertex3d(-15.0, -15.0, 4.0);
		glTexCoord2d(1.0, 0.0); glVertex3d(-15.0, 15.0, 4.0);
		glTexCoord2d(1.0, 1.0); glVertex3d(15.0, 15.0, 4.0);
		glTexCoord2d(0.0, 1.0); glVertex3d(15.0, -15.0, 4.0);
	glEnd();	

	//floor?
//	glColor3f(0.0, 1.0, 0.0);
	Texture tex2("./textures/floor1.jpg");
	glBegin(GL_POLYGON);
                glTexCoord2d(0.0, 0.0); glVertex3d(-15.0, -15.0, -6.0);
                glTexCoord2d(1.0, 0.0); glVertex3d(-15.0, 15.0, -6.0);
                glTexCoord2d(1.0, 1.0); glVertex3d(15.0,  15.0, -6.0);
                glTexCoord2d(0.0, 1.0); glVertex3d(15.0, -15.0, -6.0);
	glEnd();
	
	//front face
	//glColor3f(1.0, 0.0, 0.0);
	Texture tex3("./textures/wall 5.jpg");
	glBegin(GL_POLYGON);
		glTexCoord2d(0.0, 0.0); glVertex3d(15.0, -15.0, 4.0);
		glTexCoord2d(1.0, 0.0); glVertex3d(15.0, 15.0, 4.0);
		glTexCoord2d(1.0, 1.0); glVertex3d(15.0, 15.0, -6.0);
		glTexCoord2d(0.0, 1.0); glVertex3d(15.0, -15.0, -6.0);
	glEnd();

	//back side?
	//glColor3f(1.0, 1.0, 0.0);
	Texture tex4("./textures/wall 1.jpg");
        glBegin(GL_POLYGON);
            		glTexCoord2d(0.0, 0.0);	   glVertex3d(-15.0, -15.0, -6.0);
                	glTexCoord2d(0.0, 1.0);    glVertex3d(-15.0, 15.0, -6.0);
                	glTexCoord2d(1.0, 1.0);	   glVertex3d(-15.0, 15.0, 4.0);
                	glTexCoord2d(0.0, 1.0);    glVertex3d(-15.0, -15.0, 4.0);
        glEnd();

	

	//right side
//	glColor3f(1.0, 0.0, 1.0);
	Texture tex5("./textures/wall 5.jpg");
        glBegin(GL_POLYGON);
               glTexCoord2d(0.0, 0.0); glVertex3d(-15.0, 15.0, 4.0);
               glTexCoord2d(1.0, 0.0); glVertex3d(-15.0, 15.0, -6.0);
               glTexCoord2d(1.0, 1.0); glVertex3d(15.0, 15.0, -6.0);
               glTexCoord2d(0.0, 1.0); glVertex3d(15.0, 15.0, 4.0);
        glEnd();

	//left side
//	glColor3f(0.0, 1.0, 1.0);
	Texture tex6("./textures/wall 5.jpg");
        glBegin(GL_POLYGON);
               glTexCoord2d(0.0, 0.0);  glVertex3d(-15.0, -15.0, -6.0);
               glTexCoord2d(1.0, 0.0); glVertex3d(-15.0, -15.0, 4.0);
               glTexCoord2d(1.0, 1.0);  glVertex3d(15.0, -15.0, 4.0);
               glTexCoord2d(0.0, 1.0); glVertex3d(15.0, -15.0, -6.0);
        glEnd();
}

void drawExtras()
{
	//draw door 
	/*glColor3f(1.0, 1.0, 1.0);
	glScalef(
	glTranslatef(
	glutWireCube(1.0);

	//draw Window
	glColor3f(0.0, 0.0, 0.0);
	glScalef(
	glTranslatef(
	glutwireCube(1.0);*/
}

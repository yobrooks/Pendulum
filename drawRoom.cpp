#include "openGl.h"
#include "prototypes.h"
#include "globals.h"
#include <iostream>

void drawLeg()
{
	glColor3f(0.3, 0.2, 0.0);
	glScalef(0.2, 0.2,0.75);
	glutSolidCube(1.0);
}

void drawTable()
{
	//draw base of table
	glPushMatrix();
	glScalef(1.3, 3.0, .2);
	glTranslatef(-2.1, -0.25, -4.0);
	glColor3f(0.3, 0.2, 0.0);
	glutSolidCube(1.0);
	glPopMatrix();

//draw four legs
	glPushMatrix();
	glTranslatef(-2.8, -0.1, -1.2);
	drawLeg();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.8, -1.4, -1.2);
	drawLeg();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.8, -0.1, -1.2);
	drawLeg();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.8, -1.4, -1.2);
	drawLeg();
	glPopMatrix();
		
}

void defineWalls()
{
	//ceiling?
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
		glVertex3d(-5.0, -5.0, 2.0);
		glVertex3d(-5.0, 5.0, 2.0);
		glVertex3d(5.0, 5.0, 2.0);
		glVertex3d(5.0, -5.0, 2.0);
	glEnd();	

	//floor?
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
		glVertex3d(-5.0, -5.0, -2.0);
		glVertex3d(-5.0, 5.0, -2.0);
		glVertex3d(5.0, 5.0, -2.0);
		glVertex3d(5.0,-5.0, -2.0);
	glEnd();
	
	//front face
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
		glVertex3d(5.0, -5.0, 2.0);
		glVertex3d(5.0, 5.0, 2.0);
		glVertex3d(5.0, 5.0, -2.0);
		glVertex3d(5.0, -5.0, -2.0);
	glEnd();

	//back side?
	glColor3f(1.0, 1.0, 0.0);
        glBegin(GL_POLYGON);
                glVertex3d(-5.0, -5.0, -2.0);
                glVertex3d(-5.0, 5.0, -2.0);
                glVertex3d(-5.0, 5.0, 2.0);
                glVertex3d(-5.0, -5.0, 2.0);
        glEnd();

	//right side
	glColor3f(1.0, 0.0, 1.0);
        glBegin(GL_POLYGON);
                glVertex3d(-5.0, 5.0, 2.0);
                glVertex3d(-5.0, 5.0, -2.0);
                glVertex3d(5.0, 5.0, -2.0);
                glVertex3d(5.0, 5.0, 2.0);
        glEnd();

	//left side
	glColor3f(0.0, 1.0, 1.0);
        glBegin(GL_POLYGON);
                glVertex3d(-5.0, -5.0, -2.0);
                glVertex3d(-5.0, -5.0, 2.0);
                glVertex3d(5.0, -5.0, 2.0);
                glVertex3d(5.0, -5.0, -2.0);
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

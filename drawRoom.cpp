#include "openGl.h"
#include "prototypes.h"

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
	glTranslatef(-0.5, 0.0, -4.5);
	glColor3f(0.3, 0.2, 0.0);
	glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.6, 4.0, -5.5);
	drawLeg();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.6, -4.0, -5.5);
	drawLeg();
	glPushMatrix();
	
	
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

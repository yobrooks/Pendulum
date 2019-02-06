#include "openGl.h"
#include "prototypes.h"
#include "globals.h"
#include <math.h>
#include <iostream>



void drawSphere()
{
       glPushMatrix();
       glTranslated(0.0, 0.2, 0.0);
       glTranslated(0.0,0.0,2.0);
       glRotated((double)180*theta/M_PI, 1, 0, 0);
       glTranslated(0.0,0.0,-2.0);
       glColor3f (0.0,0.0,1.0);
       gluSphere(gluNewQuadric(),
            (GLdouble) 0.3,
            (GLint)    10,
            (GLint)    10 );
       glPopMatrix();

}

void drawStand()
{
	//draw base
	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glScaled(5.0, 5.0, 0.5);
	glTranslated(0.0, 0.0, -4.5);
	glutSolidCube(1.0);
	glPopMatrix();

        //draw stand on top of base
	glPushMatrix();
	glTranslated(0.0, 2.0, 0.0);
	glTranslated(0.0, 0.0, -2.0);
	glColor3f(1.0, 0.0, 0.0);
	gluCylinder(gluNewQuadric(),
		(GLdouble) 0.2,
		(GLdouble) 0.2,
		(GLdouble) 4.5,
		(GLint) 20, (GLint) 40);
	glPopMatrix();
	
	//draw arm
	glPushMatrix();
	glTranslated(0.0, 2.2, 2.7);
	glRotated(90.0, 1.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 0.0);
	gluCylinder(gluNewQuadric(), 
		(GLdouble) 0.2,
		(GLdouble) 0.2,
		(GLdouble) 2.5, 
		(GLint) 10, (GLint) 10);
	glPopMatrix();


	//draw string
	glPushMatrix();
	glTranslated(0.0, 0.2, 0.0);
        glTranslated(0.0, 0.0, 2.0);
        glRotated((double)180*theta/M_PI,1.0, 0.0, 0.0);
        glTranslated(0.0, 0.0, -2.0);
        glColor3f(1.0, 0.0, 1.0);
        gluCylinder(gluNewQuadric(),
                (GLdouble) 0.1,
                (GLdouble) 0.1,
                (GLdouble) 2.8,
                (GLint) 10, (GLint) 10);
        glPopMatrix();

}

void drawScale()
{
	glColor3f(0.0, 1.0, 1.0);

	glPushMatrix();
	glTranslated(0.0, 5.0, 4.0);

	//head
	gluSphere(gluNewQuadric(), 
		(GLdouble) 1.2,
		(GLint) 20,
		(GLint) 20);

	glPopMatrix();

	//neck/body
	glPushMatrix();
	glTranslated(0.0, 5.0, 0.0);
	glTranslated(0.0, 0.0, -1.5);
	gluCylinder(gluNewQuadric(),
		(GLdouble) 0.2,
		(GLdouble) 0.2,
		(GLdouble) 4.5,
		(GLint) 10,(GLint) 10);

	glPopMatrix();	

	//arms
	glPushMatrix();
	glTranslated(0.0, 4.8, 1.3);
	glRotated(80.0, 1.0, 0.0, 0.0);
	gluCylinder(gluNewQuadric(), 
		(GLdouble) 0.2,
		(GLdouble) 0.2,
		(GLdouble) 2.0,
		(GLint) 10, (GLint) 10);

	glPopMatrix();

	glPushMatrix();
	glTranslated(0.0, 5.2, 1.3);
	glRotated(-80.0, 1.0, 0.0, 0.0);
	gluCylinder(gluNewQuadric(),
		(GLdouble) 0.2,
		(GLdouble) 0.2,
		(GLdouble) 2.0,
		(GLint) 10, (GLint) 10);

	glPopMatrix();

	//legs 
	glPushMatrix();
	glTranslated(0.0, 4.9, -1.5);
	glRotated(150.0, 1.0, 0.0, 0.0);
	gluCylinder(gluNewQuadric(),
		(GLdouble) 0.2,
		(GLdouble) 0.2,
		(GLdouble) 2.5,
		(GLint) 10, (GLint) 10);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.0, 5.1, -1.5);
	glRotated(-150.0, 1.0, 0.0, 0.0);
	gluCylinder(gluNewQuadric(),
		(GLdouble) 0.2,
		(GLdouble) 0.2,
		(GLdouble) 2.5,
		(GLint) 10, (GLint) 10);

	glPopMatrix();
}

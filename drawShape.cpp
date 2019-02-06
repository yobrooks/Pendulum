#include "openGl.h"
#include "prototypes.h"
#include "globals.h"
#include <math.h>
#include <iostream>


//make smaller 
void drawSphere()
{
    glPushMatrix();
       //glTranslated(0.0,2.0,0.0);
       //glRotated((double)180*theta/M_PI, 1, 0, 0);
       //glRotated((double)180*theta/M_PI, 0, 0, 1);
       //glTranslated(2.0,0.0,0.0);
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

//draw stand on top of base //move further back 
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
	glTranslated(0.0, 2.2, 0.0);
	glTranslated(0.0, 0.0, 2.7);
	glRotated(90.0, 1.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 0.0);
	gluCylinder(gluNewQuadric(), 
		(GLdouble) 0.2,
		(GLdouble) 0.2,
		(GLdouble) 2.5, 
		(GLint) 10, (GLint) 10);
	glPopMatrix();


	
	glPushMatrix();
        //glTranslated(0.0, 0.0, 0.0);
       // glTranslated(0.0, 0.0, 2.3);
       // glRotated((double)180*theta/M_PI,1.0, 0.0, 0.0);
       // glTranslated(0.0, 0.0, -2.3);
        glColor3f(1.0, 0.0, 1.0);
        gluCylinder(gluNewQuadric(),
                (GLdouble) 0.1,
                (GLdouble) 0.1,
                (GLdouble) 2.5,
                (GLint) 10, (GLint) 10);
        glPopMatrix();

}

void drawScale()
{
	glColor3f(0.0, 1.0, 1.0);
	glPushMatrix();
	glTranslated(0.0, 5.0, 0.0);

	//head
	//glColor3f(0.0, 1.0, 1.0);
	gluSphere(gluNewQuadric(), 
		(GLdouble) 1.0,
		(GLint) 20,
		(GLint) 20);

	glPopMatrix();

	//neck/body
	glPushMatrix();
//	glColor3f(0.0, 1.0, 1.0);
	glTranslated(0.0, 5.0, 0.0);
	glTranslated(0.0, 0.0, -3.0);
	gluCylinder(gluNewQuadric(),
		(GLdouble) 0.2,
		(GLdouble) 0.2,
		(GLdouble) 3.0,
		(GLint) 10,(GLint) 10);

	glPopMatrix();	

	glPushMatrix();
	//arms
//	glColor3f(0.0, 1.0, 1.0);
	glTranslated(0.0, 4.8, -1.5);
	glRotated(80.0, 1.0, 0.0, 0.0);
	gluCylinder(gluNewQuadric(), 
		(GLdouble) 0.2,
		(GLdouble) 0.2,
		(GLdouble) 1.0,
		(GLint) 10, (GLint) 10);

	glPopMatrix();

	glPushMatrix();
//	glColor3f(0.0, 1.0, 1.0);
	glTranslated(0.0, 5.2, -1.5);
	glRotated(-80.0, 1.0, 0.0, 0.0);
	gluCylinder(gluNewQuadric(),
		(GLdouble) 0.2,
		(GLdouble) 0.2,
		(GLdouble) 1.0,
		(GLint) 10, (GLint) 10);

	glPopMatrix();

	//legs 
	glPushMatrix();
	glTranslated(0.0, 4.9, -2.7);
	glRotated(155.0, 1.0, 0.0, 0.0);
	gluCylinder(gluNewQuadric(),
		(GLdouble) 0.2,
		(GLdouble) 0.2,
		(GLdouble) 1.0,
		(GLint) 10, (GLint) 10);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.0, 5.1, -2.7);
	glRotated(-155.0, 1.0, 0.0, 0.0);
	gluCylinder(gluNewQuadric(),
		(GLdouble) 0.2,
		(GLdouble) 0.2,
		(GLdouble) 1.0,
		(GLint) 10, (GLint) 10);

	glPopMatrix();
}

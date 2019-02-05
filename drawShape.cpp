#include "openGl.h"
#include "prototypes.h"
#include "globals.h"
#include <math.h>
#include <iostream>


//make smaller 
void drawSphere()
{
    glPushMatrix();
      // glTranslated(0.0,2.0,0.0);
       //glRotated((double)180*theta/M_PI, 1, 0, 0);
       //glRotated((double)180*theta/M_PI, 0, 0, 1);
      // glTranslated(2.0,0.0,0.0);
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
	glPushMatrix();
	glTranslated(0.0, 5.0, 0.0);

	//head
	glColor3f(0.0, 1.0, 1.0);
	gluSphere(gluNewQuadric(), 
		(GLdouble) 1.0,
		(GLint) 20,
		(GLint) 20);

	glPopMatrix();

	//neck/body
	glPushMatrix();
	glColor3f(0.0, 1.0, 1.0);
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
	glColor3f(0.0, 1.0, 1.0);
	glRotated(90.0, 1.0, 0.0, 0.0);
	gluCylinder(gluNewQuadric(), 
		(GLdouble) 0.2,
		(GLdouble) 0.2,
		(GLdouble) 2.0,
		(GLint) 10, (GLint) 10);

	glPopMatrix();
/*	glTranslated(0.0, 0.0, 6.0);
	gluCylinder(gluNewQuadric(),
		(GLdouble) 0.5,
		(GLdouble) 0.5,
		(GLdouble) 2.0,
		(GLint) 10, (GLint) 10);

	//legs 
	glTranslated(6.0, 0.0, 0.0);
	gluCylinder(gluNewQuadric(),
		(GLdouble) 0.5,
		(GLdouble) 0.5,
		(GLdouble) 2.0,
		(GLint) 10, (GLint) 10);

	glRotated(90.0, 0.0, 1.0, 0.0);
	gluCylinder(gluNewQuadric(),
		(GLdouble) 0.5,
		(GLdouble) 0.5,
		(GLdouble) 2.0,
		(GLint) 10, (GLint) 10);

	glPopMatrix();*/
}

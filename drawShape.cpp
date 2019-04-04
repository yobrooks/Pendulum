#include "openGl.h"
#include "prototypes.h"
#include "globals.h"
#include <math.h>
#include <iostream>

//draw the pendulum ball
void drawSphereColor()
{
       glPushMatrix();
       glTranslated(0.0, -0.4, 0.0);
       glTranslated(0.0,0.0,2.7);
       glRotated((double)180*theta/M_PI, 0, 1, 0);
       glTranslated(0.0,0.0,-2.7);
       glColor3f (1.0,1.0,1.0);
       gluSphere(gluNewQuadric(),
            (GLdouble) 0.6,
            (GLint)    10,
            (GLint)    10 );
       glPopMatrix();


}

void drawSphereText()
{
	//the movement of the string is off, also need to raise the pendulum severely

	glBindTexture(GL_TEXTURE_2D, textures[6]);
	GLUquadric *disco;
	disco = gluNewQuadric();
	gluQuadricTexture(disco, GL_TRUE);
	glPushMatrix();
	glTranslated(0.0, -0.4, 0.0);
        glTranslated(0.0,0.0,2.7);
        glRotated((double)180*theta/M_PI, 0, 1, 0);
        glTranslated(0.0,0.0,-2.7);
	gluSphere(disco, 0.6, 10, 10);
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, textures[7]);
	GLUquadric *cord;
	cord = gluNewQuadric();
	gluQuadricTexture(cord, GL_TRUE);
	glPushMatrix();
        glTranslated(0.0, -0.4, 0.0);
        glTranslated(0.0, 0.0, 2.7); //swings with the ball
        glRotated((double)180*theta/M_PI,0.0, 1.0, 0.0);
        glTranslated(0.0, 0.0, -2.7);
        glColor3f(1.0, 1.0, 1.0);
        gluCylinder(cord,
                (GLdouble) 0.05,
                (GLdouble) 0.05,
                (GLdouble) 2.8,
                (GLint) 10, (GLint) 10);
        glPopMatrix();

	
}
//draw the stand that the pendulum ball is attached to 
void drawStand()
{


	//draw string
	glPushMatrix();
	glTranslated(0.0, -0.4, 0.0);
        glTranslated(0.0, 0.0, 2.7); //swings with the ball
        glRotated((double)180*theta/M_PI,0.0, 1.0, 0.0);
        glTranslated(0.0, 0.0, -2.7);
        glColor3f(1.0, 1.0, 1.0);
        gluCylinder(gluNewQuadric(),
                (GLdouble) 0.05,
                (GLdouble) 0.05,
                (GLdouble) 2.8,
                (GLint) 10, (GLint) 10);
        glPopMatrix();


}

//draw scale factor
void drawScale()
{
	glColor3f(0.0, 1.0, 1.0);

	glPushMatrix();
	glTranslated(0.0, 5.0, 3.0);

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
		(GLdouble) 4.2,
		(GLint) 10,(GLint) 10);

	glPopMatrix();	

	//arms
	glPushMatrix();
	glTranslated(0.0, 4.8, 0.8);
	glRotated(80.0, 1.0, 0.0, 0.0);
	gluCylinder(gluNewQuadric(), 
		(GLdouble) 0.2,
		(GLdouble) 0.2,
		(GLdouble) 2.0,
		(GLint) 10, (GLint) 10);

	glPopMatrix();

	glPushMatrix();
	glTranslated(0.0, 5.2, 0.8);
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

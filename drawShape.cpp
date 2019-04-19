#ifndef DRAWSHAPE_CPP
#define DRAWSHAPE_CPP

#include "openGl.h"
#include "prototypes.h"
#include "globals.h"
#include <math.h>
#include <iostream>

//draw the untextured pendulum ball and string
GLfloat lightDifTwo[] = {1.0, 0.2, 1.0, 1.0};
GLfloat white[] = {1.0, 1.0, 1.0, 1.0};
GLfloat shine = 100.0;
GLfloat black [] = {0.0, 0.0, 0.0, 1.0};
GLfloat spotPos [] = {5.5, 5.0, 2.5, 1.0};
GLfloat spotLight [] = {1.0, 1.0, 0.0, 0.0};
GLfloat direction [] = {0.0, -1.0, 0.0};
void drawSphereColor()
{
	glDisable(GL_LIGHTING);
	//string
	glPushMatrix();
        glTranslated(5.0, 0.0, 2.5);
        glTranslated(0.0, 0.0, 2.0);
        glRotated((double)180*theta/M_PI,0.0, 1.0, 0.0);
        glTranslated(0.0, 0.0, -2.0);
        glColor3f(1.0, 1.0, 1.0);
        gluCylinder(gluNewQuadric(),
                (GLdouble) 0.05,
                (GLdouble) 0.05,
                (GLdouble) 1.5,
                (GLint) 10, (GLint) 10);
        glPopMatrix();


	//ball
       glPushMatrix();
       glTranslated(5.0, 0.0, 2.0);
       glTranslated(0.0,0.0, 2.0);
       glRotated((double)180*theta/M_PI, 0, 1, 0);
       glTranslated(0.0,0.0,-2.0);
       glColor3f (1.0,1.0,1.0);
       gluSphere(gluNewQuadric(),
            (GLdouble) 0.6,
            (GLint)    20,
            (GLint)    20 );
       glPopMatrix();
}

void setSpotlight()
{
   glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 20.0);
   glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, 30.0);
   glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, 0.0);

   glLightfv(GL_LIGHT3, GL_POSITION, spotPos);
   glLightfv(GL_LIGHT3, GL_AMBIENT, black);
   glLightfv(GL_LIGHT3, GL_DIFFUSE, spotLight);
   glLightfv(GL_LIGHT3, GL_SPECULAR, spotLight);

    //direction
   glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, direction);

}
//draw the sphere and string textured version
void drawSphereText()
{
	setSpotlight();
	//draw ball
	glBindTexture(GL_TEXTURE_2D, textures[3]);
	GLUquadric *disco;
	disco = gluNewQuadric();
	gluQuadricTexture(disco, GL_TRUE);
	glPushMatrix();
	glTranslated(5.0, 0.0, 2.0);
        glTranslated(0.0,0.0, 2.0);
        glRotated((double)180*theta/M_PI, 0, 1, 0);
        glTranslated(0.0,0.0,-2.0);

	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &shine);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, lightDifTwo);
	gluSphere(disco, 0.6, 40, 40); //draw sphere
	glPopMatrix();

	//draw string
	glBindTexture(GL_TEXTURE_2D, textures[4]);
	GLUquadric *cord;
	cord = gluNewQuadric();
	gluQuadricTexture(cord, GL_TRUE);
	glPushMatrix();
        glTranslated(5.0, 0.0, 2.5);
        glTranslated(0.0, 0.0, 2.0); //swings with the ball
        glRotated((double)180*theta/M_PI,0.0, 1.0, 0.0);
        glTranslated(0.0, 0.0, -2.0);
        glColor3f(1.0, 1.0, 1.0);
        gluCylinder(cord,
                (GLdouble) 0.05,
                (GLdouble) 0.05,
                (GLdouble) 1.5,
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

#endif

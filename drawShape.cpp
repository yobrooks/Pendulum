#include "openGl.h"
#include "prototypes.h"
#include "globals.h"
#include <math.h>

void drawSphere()
{
    glPushMatrix();
 //      glTranslated(2.0,0.0,0.0);
       glRotated((double)180*theta/M_PI, 1, 0, 0);
       glRotated((double)180*theta/M_PI, 0, 0, 1);
       glTranslated(2.0,0.0,0.0);
       glColor3f (0.0,0.0,1.0);
       gluSphere(gluNewQuadric(),
            (GLdouble) 0.5,
            (GLint)    10,
            (GLint)    10 );
     glPopMatrix();
}

void drawBase()
{
	glPushMatrix();
	glTranslated(0.0, 5.0, 0.0); //moved it to the right
	glTranslated(0.0, 0.0, -3.0); 
	glColor3f(0.0, 1.0, 0.0);
	gluCylinder(gluNewQuadric(), 
		(GLdouble) 1.0,
		(GLdouble) 1.0,
		(GLdouble) 1.0,
		(GLint) 20, (GLint) 20);
	glPopMatrix();
}

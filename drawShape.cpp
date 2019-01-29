#include "openGl.h"
#include "prototypes.h"
#include "globals.h"
#include <math.h>
#include <iostream>


//make smaller 
void drawSphere()
{
    glPushMatrix();
       //glTranslated(10.0,0.0,0.0);
       glRotated((double)180*theta/M_PI, 1, 0, 0);
       glRotated((double)180*theta/M_PI, 0, 0, 1);
       glTranslated(2.0,0.0,0.0);
       glColor3f (0.0,0.0,1.0);
       gluSphere(gluNewQuadric(),
            (GLdouble) 0.5,
            (GLint)    10,
            (GLint)    10 );
     glPopMatrix();

 	//std::cout << "Theta: " << theta << std::endl;
}

/*void drawArm()
{
	
}

drawStand()
{
	
}*/

void drawBase()
{
	glPushMatrix();
	glTranslated(0.0, 5.0, 0.0); //moved it to the right
	glTranslated(0.0, 0.0, -3.0); 
	glColor3f(0.0, 1.0, 0.0);
	//gluQuadricDrawStyle(gluCylinder, GL_FILL);
	gluCylinder(gluNewQuadric(), 
		(GLdouble) 2.0,
		(GLdouble) 2.0,
		(GLdouble) 1.0,
		(GLint) 40, (GLint) 40);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.0, 5.0, 0.0);
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
	glRotated(180.0, 0.0, 1.0, 0.0);
	glColor3f(1.0, 1.0, 0.0);
	gluCylinder(gluNewQuadric(), 
		(GLdouble) 0.1,
		(GLdouble) 0.1,
		(GLdouble) 1.0, 
		(GLint) 10, (GLint) 10);
	glPopMatrix();
}

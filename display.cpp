#include "openGl.h"
#include "prototypes.h"
#include "globals.h"
#include <math.h>

void display()
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLoadIdentity();
    gluLookAt( 20.0,   0.0, 5.0,  // Eye
                0.0,   0.0, 0.0,  // Center
                0.0,   0.0, 1.0); // Up

    glEnable(GL_DEPTH_TEST);

    glColor3f(0.0,1.0,0.0);
  

    glPushMatrix();
    glTranslated(2.0,0.0,0.0);
    glRotated((double)180*theta/M_PI, 1, 0, 0);
    glRotated((double)180*theta/M_PI, 0, 0, 1);
    glTranslated(2.0,0.0,0.0);
    glColor3f (0.0,0.0,1.0);
    gluSphere(gluNewQuadric(),
            (GLdouble) 0.5,
            (GLint)    10,
            (GLint)    10 );
    glPopMatrix();

  //  showFPS();
    glutSwapBuffers();
}

#include "openGl.h"
#include "prototypes.h"
#include "globals.h"

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
    glColor3f (0.0,0.0,1.0);
    gluCylinder(gluNewQuadric(),
            (GLdouble) 0.1,
            (GLdouble) 0.1,
            (GLdouble) 4.0,
            (GLint)    20,
            (GLint)    20 );
    glPopMatrix();

    glFlush();
}

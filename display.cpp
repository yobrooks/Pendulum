#include "openGl.h"
#include "prototypes.h"
#include "globals.h"
#include <math.h>
#include <iostream>
void display()
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLoadIdentity();
//    gluLookAt( 20.0,   -10.0, 10.0,  // Eye
      gluLookAt(20.0, 0.0, 5.0,
                0.0,   0.0, 0.0,  // Center
                0.0,   0.0, 1.0); // Up

    glEnable(GL_DEPTH_TEST);

    glColor3f(0.0,1.0,0.0);
  

    //drawing everything on the screen; make a separate function for this junk
    drawSphere();
    drawStand();
    drawTable();
    //drawScale();
    drawPeriod();
    //determines if synch needs to be applied
    if(desiredFR>0.0)
    {
	glutLockFrameRate();
    }
    glutSwapBuffers();
}

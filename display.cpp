#include "openGl.h"
#include "prototypes.h"
#include "globals.h"
#include <math.h>
#include <iostream>



void display()
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLoadIdentity();
   // gluLookAt( 20.0,   -10.0, 10.0,  // Eye
      /*gluLookAt(CAM_A*sin(CAM_B*M_PI/180.0) * cos(CAM_C*M_PI/180.0),
 		CAM_A*sin(CAM_B*M_PI/180.0)*sin(CAM_C*M_PI/180.0),
	        CAM_A*cos(CAM_B*M_PI/180.0),
                CENTER_X,   CENTER_Y, CENTER_Z,  // Center
                0.0,   0.0, 1.0); // Up*/

      gluLookAt(15.0, 10.0, 0.0,
		0.0, 0.0, 0.0,
		0.0, 0.0, 1.0);

    glEnable(GL_DEPTH_TEST);

    glColor3f(0.0,1.0,0.0);
  

    //drawing everything on the screen; make a separate function for this junk
   // drawSphere();
    //drawScale();
    //drawPeriod();
    drawStand();
    drawSphere();
    defineWalls();
    drawTable();
    //determines if synch needs to be applied
    if(desiredFR>0.0)
    {
	glutLockFrameRate();
    }
    glutSwapBuffers();
}

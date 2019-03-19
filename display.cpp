#include "openGl.h"
#include "prototypes.h"
#include "globals.h"
#include <math.h>
#include <iostream>
#include "Texture.h"
#include "Camera.h"


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

 /*     gluLookAt(camera.eye[0], camera.eye[1], camera.eye[2],
		camera.center[0], camera.center[1], camera.center[2],
		camera.up[0], camera.up[1], camera.up[2]);*/

	gluLookAt(10.0, 0.0, 0.0,
                0.0, 0.0, 0,
                0.0, 0.0, 1.0);


    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
  

    //bind();
    //drawing everything on the screen; make a separate function for this junk
   // drawSphere();
    //drawScale();
    //drawPeriod();
    //drawStand();
   // drawSphere();
    //defineWallsText();
   // drawTable();
   //
 /*  Texture tex2("./textures/studio54.jpg");
   glBegin(GL_POLYGON);

      glTexCoord2d( 0.0, 0.0);   glVertex2d(  0.0,  0.0);
      glTexCoord2d( 0.0, 1.0);   glVertex2d(  0.0, 10.0);
      glTexCoord2d( 1.0, 1.0);   glVertex2d( 10.0, 10.0);
      glTexCoord2d( 1.0, 0.0);   glVertex2d( 10.0,  0.0 );

    glEnd();*/
    //determines if synch needs to be applied
    if(desiredFR>0)
    {
//	glutLockFrameRate();
	drawStand();

	drawSphereColor();
	drawRoomColor();
    }

   else{
		drawStand();
		drawSphereText();
		defineWallsText();

	}

    glutSwapBuffers();
 //
    //glFlush();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);

    
}

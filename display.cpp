#ifndef DISPLAY_CPP
#define DISPLAY_CPP

#include "openGl.h"
#include "prototypes.h"
#include "globals.h"
#include <math.h>
#include <iostream>
#include "Camera.h"
#include <vector>
Camera camera;
void display()
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLoadIdentity();

      gluLookAt(camera.eye[0], camera.eye[1], camera.eye[2],
		camera.center[0], camera.center[1], camera.center[2],
		camera.up[0], camera.up[1], camera.up[2]);
//	std::cout << camera.eye[0] << " " <<camera.eye[1] << " " <<camera.eye[2] << std::endl;
		#ifdef TEXTURE
		glEnable(GL_TEXTURE_2D);
	        glEnable(GL_DEPTH_TEST);
  
    //determines if synch needs to be applied
//	glutLockFrameRate();

		
		drawSphereText();
		defineWallsText();

   		glutSwapBuffers();

	        glDisable(GL_TEXTURE_2D);
   	  	glDisable(GL_DEPTH_TEST);
	

		#else
                drawRoomColor();
                drawSphereColor();
                glutSwapBuffers();
 		#endif   
}

#endif

#ifndef SPECIALKEYS_CPP
#define SPECIALKEYS_CPP

#include "openGl.h"
#include "globals.h"
#include <iostream>


void specialKeyboard(int key, int x, int y)
{
	if(key == GLUT_KEY_PAGE_UP)
	{
		camera.moveUp(0.2);
		glutPostRedisplay();
	}

	if(key == GLUT_KEY_PAGE_DOWN)
        {
        	camera.moveDown(0.2);    	
		glutPostRedisplay();   
        }

	 if(key == GLUT_KEY_UP)
        {
                camera.panUp(0.2);
		glutPostRedisplay();
        }

	if(key == GLUT_KEY_DOWN)
        {
         	camera.panDown(0.2);   
		glutPostRedisplay();    
        }

	 if(key == GLUT_KEY_LEFT)
        {
        	camera.panLeft(0.2);  
		glutPostRedisplay();     
        }

	 if(key == GLUT_KEY_RIGHT)
        {
         	camera.panRight(0.2);   
		glutPostRedisplay();
        }
}

#endif

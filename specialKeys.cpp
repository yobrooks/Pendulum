#include "openGl.h"
#include "globals.h"
//#include "Camera.h"
#include <iostream>


void specialKeyboard(int key, int x, int y)
{
	if(key == GLUT_KEY_PAGE_UP)
	{
		camera.moveUp(0.2);
	}

	if(key == GLUT_KEY_PAGE_DOWN)
        {
        	camera.moveDown(0.2);       
        }

	 /*if(key == GLUT_KEY_UP)
        {
                
        }

	if(key == GLUT_KEY_DOWN)
        {
                
        }

	 if(key == GLUT_KEY_LEFT)
        {
                
        }

	 if(key == GLUT_KEY_RIGHT)
        {
            
        }

	glutPostRedisplay();*/
}

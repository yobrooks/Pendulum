#include "openGl.h"
#include <iostream>
#include "globals.h"
//#include "Camera.h"

//function to allow user to quit the program with the keyboard
void keyboard(unsigned char key, int x, int y)
{
	/*switch(tolower(key))
	{
		case 'q' : exit(0); //hitting 'q'/'Q' exits the program
		case 'r' : camera.returnOriginal(); break;
		case 'w' : camera.moveForward(); break;
		case 'a' : camera.moveLeft(); break;
		case 's' : camera.moveBackward(); break;
		case 'd' : camera.moveRight(); break;
	}*/

	glutPostRedisplay();
}

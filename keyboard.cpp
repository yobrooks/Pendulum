#include "openGl.h"
#include <iostream>
#include "globals.h"
//#include "Camera.h"

//function to allow user to quit the program with the keyboard
void keyboard(unsigned char key, int x, int y)
{
	switch(tolower(key))
	{
		case 'q' : exit(0); //hitting 'q'/'Q' exits the program
		case 'r' : camera.returnOriginal(); glutPostRedisplay(); break;
		case 'w' : camera.moveForward(); glutPostRedisplay(); break;
		case 'a' : camera.moveLeft(); glutPostRedisplay(); break;
		case 's' : camera.moveBackward(); glutPostRedisplay(); break;
		case 'd' : camera.moveRight(); glutPostRedisplay(); break;
	}

}

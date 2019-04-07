#ifndef KEYBOARD_CPP
#define KEYBOARD_CPP

#include "openGl.h"
#include <iostream>
#include "globals.h"
//#include "Camera.h"

//function to allow user to interact with the program with the keyboard
void keyboard(unsigned char key, int x, int y)
{
	switch(tolower(key))
	{
		case 'q' : exit(0); //hitting 'q'/'Q' exits the program
		case 'r' : camera.returnOriginal(); glutPostRedisplay(); break;
		case 'w' : camera.moveForward(0.2); glutPostRedisplay(); break;
		case 'a' : camera.moveLeft(0.2); glutPostRedisplay(); break;
		case 's' : camera.moveBackward(0.2); glutPostRedisplay(); break;
		case 'd' : camera.moveRight(0.2); glutPostRedisplay(); break;
	}

}

#endif

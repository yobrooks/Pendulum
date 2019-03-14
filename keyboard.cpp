#include "openGl.h"
#include <iostream>

//function to allow user to quit the program with the keyboard
void keyboard(unsigned char key, int x, int y)
{
	switch(tolower(key))
	{
		case 'q' : exit(0); //hitting 'q'/'Q' exits the program
		case 'r' : std::cout << "Revert to default camera" << std::endl; break;
		case 'w' : std::cout << "Move forward" << std::endl; break;
		case 'a' : std::cout << "Move left" << std::endl; break;
		case 's' : std::cout << "Move backward" << std::endl; break;
		case 'd' : std::cout << "Move right" << std::endl; break;
	}
}

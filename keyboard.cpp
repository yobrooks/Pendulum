#include "openGl.h"
#include <iostream>

//function to allow user to quit the program with the keyboard
void keyboard(unsigned char key, int x, int y)
{
	switch(tolower(key))
	{
		case 'q' : exit(0); //hitting 'q'/'Q' exits the program
	}
}

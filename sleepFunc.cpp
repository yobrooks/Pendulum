#include "openGl.h"
#include "prototypes.h"
#include "globals.h"
#include <iostream>
#include <sstream>


void glutLockFrameRate()
{
	int millisecondsToWait= (int)(1/desiredFR*1000);
	int startTime = glutGet(GLUT_ELAPSED_TIME);
	do{

	  } while((glutGet(GLUT_ELAPSED_TIME) -startTime) < millisecondsToWait);
}

void askSynch(int num, char** args)
{
	if(num>=2)	
	{
		std::istringstream iss(args[1]);
		int temp;
		if(iss >> temp)
		{
			//std::cout << "Successful " << std::endl;
			desiredFR = (float) temp;
		}
	}			
}

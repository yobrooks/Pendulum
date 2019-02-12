#include "openGl.h"
#include "prototypes.h"
#include "globals.h"
#include <sstream>

//function to lock the frame rate
//given by Dr. Pounds
void glutLockFrameRate()
{
	int millisecondsToWait= (int)(1/desiredFR*1000);
	int startTime = glutGet(GLUT_ELAPSED_TIME);
	do{

	  } while((glutGet(GLUT_ELAPSED_TIME) -startTime) < millisecondsToWait);
}

//function to figure out if there needs to be 
//synchronization based on command line arguments
void askSynch(int num, char** args)
{
	if(num>=2)	//if the number of arguments is at least 2
	{
		std::istringstream iss(args[1]); //use input stream to store value of the 2nd argument
		int temp;
		if(iss >> temp) //store argument in temp variable
		{
			desiredFR = (float) temp; //make the temp argument the desired frame rate
		}
	}			
}

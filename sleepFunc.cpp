#include "openGl.h"


void glutSleep(int millisecondsToWait)
{
	int startTime = glutGet(GLUT_ELAPSED_TIME);
	do{

	  } while((glutGet(GLUT_ELAPSED_TIME) -startTime) < millisecondsToWait);
}

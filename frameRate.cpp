#include "openGl.h"
#include "globals.h"
#include <iostream>
#include <stdio.h>

void showFPS()
{
	float fps;
	frame++;
	int currentTime = glutGet(GLUT_ELAPSED_TIME);
	
	if(currentTime-oldTime > 1000)
	{
		fps = (frame*1000.0)/(currentTime - oldTime);
		oldTime = currentTime;
		printf("FPS = %.0f\n",fps);
		frame = 0;
	}
}

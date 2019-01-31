#include "openGl.h"
#include "globals.h"
#include <iostream>
#include <stdio.h>

//float findFPS()
void findFPS()
{
//	float fps;
	frame++;
	int currentTime = glutGet(GLUT_ELAPSED_TIME);
	
	if(currentTime-oldTime > 1000)
	{
		fps = (frame*1000.0)/(currentTime - oldTime);
		oldTime = currentTime;
	//	std::cout << "FPS: " << fps << std::endl;

		//theta = angle, omega = velocity
		//how long period is in frames; calculate when omega changes signs and multiple by 2
		frame = 0;
	}

	//return fps;
}

void drawString(int x, int y, void *font, const char *string)
{
	
	const char  *c;
	glRasterPos2i(x, y);
	for(c = string; *c!='\0'; c++)
	{
		glutBitmapCharacter(font, *c);
	}	
}

void drawFPS()
{

	findFPS();
//	std::cout << "FPS: " << fps << std::endl;
	char *charString = (char*) malloc(12*sizeof(char));
	sprintf(charString, "FPS: %.0f", fps);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, WINDOW_HEIGHT, 0.0, WINDOW_HEIGHT);
	
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glColor3f(255, 255, 255);
	drawString(50, 50, GLUT_BITMAP_HELVETICA_12, charString);

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	free(charString);
}


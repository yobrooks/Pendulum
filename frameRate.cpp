#include "openGl.h"
#include "globals.h"
#include <iostream>
#include <stdio.h>

static bool pStart=false, pEnd=false, fpStart=false, fpEnd=false;
static long int totFrame=0;
static double timeCount=0.0, prevTimeCount=0.0;

//function to calculate the period of the pendulum and frames per period
void findPeriod()
{
	//if pendulum is going in positive way
	if(prevOmega*omega >=0)
	{
		if(pStart==false && pEnd==false) //if time not started yet, start "time" and update time and frames
		{
			pStart=true;
			timeCount=t;
			totFrame ++;
		}
		else if(pStart==true && pEnd==false) //if time has started and not ended, update time and frames
		{
			timeCount=t;
			totFrame++;
		}
		else if(pStart==true && pEnd==true) //if if time has started and then ended; this means one iteration of swing is done
		{
			pStart=false;
			pEnd=false;
			period=(timeCount-prevTimeCount)*2; //calculate the time change 
			fpp=totFrame*2; //calculate the total frames
			prevTimeCount=timeCount; //set previous time to current time 
			totFrame=0; //reset frame counter
		}
	}

	//if pendulum in negative direction, and "timer" has started	
	if(prevOmega*omega <0 && pStart==true && pEnd ==false)
	{
			pEnd=true; //set end "timer" to indicate it has changed directions
			//timeCount=t;
		//	totFrame++;
	}	
}

//function to find frame rate
void findFPS()
{
	frame++;
	int currentTime = glutGet(GLUT_ELAPSED_TIME);
	
	if(currentTime-oldTime > 1000)
	{
		fps = (frame*1000.0)/(currentTime - oldTime);
		oldTime = currentTime;
		frame = 0;
	}
}

//function to draw 2d text
void drawString(int x, int y, void *font, const char *string)
{
	
	const char  *c;
	glRasterPos2i(x, y);
	for(c = string; *c!='\0'; c++)
	{
		glutBitmapCharacter(font, *c);
	}	
}

//function to draw the period, fps, and fpp to the screen
void drawPeriod()
{
	findPeriod(); //find the period and fpp
	findFPS(); //find the fps

        char *charString = (char*) malloc(12*sizeof(char));
	char *a = (char*) malloc(12*sizeof(char));
	char *b = (char*) malloc(12*sizeof(char));

        sprintf(charString, "Period: %.1f sec", period);
	sprintf(a, "FPP:  %.0f", (float)fpp);
	sprintf(b, "FPS: %.0f", fps);

	//switch between appropriate modes to be able to draw 2D text in 3D screen
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        gluOrtho2D(0.0, WINDOW_HEIGHT, 0.0, WINDOW_HEIGHT);

        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();

        glColor3f(255, 255, 255);
        drawString(50, 100, GLUT_BITMAP_HELVETICA_12, charString);
	drawString(50, 75, GLUT_BITMAP_HELVETICA_12, a);
	drawString(50, 50, GLUT_BITMAP_HELVETICA_12, b);

        glPopMatrix();
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);

        free(charString);
	free(a);
	free(b);
}



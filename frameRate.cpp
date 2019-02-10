#include "openGl.h"
#include "globals.h"
#include <iostream>
#include <stdio.h>

static bool pStart=false, pEnd=false, fpStart=false, fpEnd=false;
static long int totFrame=0;
static double timeCount=0.0, prevTimeCount=0.0;

void findPeriod()
{
	if(prevOmega*omega >=0)
	{
		if(pStart==false && pEnd==false)
		{	
			pStart=true;
			timeCount=t;
		}
		else if(pStart==true && pEnd==false)
		{
			timeCount=t;
		}
		else if(pStart==true && pStart==true)
		{
			pStart=false;
			pEnd=false;
			period=(timeCount-prevTimeCount)*2;
			prevTimeCount=timeCount;
		}
	}
	
	if(prevOmega*omega <0 && pStart==true && pEnd ==false)
	{
			pEnd=true;
			timeCount=t;
	}	
}

void findFPP()
{	
	 if(prevOmega*omega >=0)
         {
                if(fpStart==false && fpEnd==false)
                {
                        fpStart=true;
                        totFrame++;
                }
                else if(fpStart==true && fpEnd==false)
                {
                  	totFrame++;
                }
                else if(fpStart==true && fpStart==true)
                {
                        fpStart=false;
                        fpEnd=false;
                        fpp=totFrame;
			std::cout<< fpp << std::endl;
                      //  totFrame=0;
                }
        }

        if(prevOmega*omega <0 && fpStart==true && fpEnd ==false)
        {
                        fpEnd=true;
                        totFrame++;
        }

}

void findFPS()
{
	frame++;
	int currentTime = glutGet(GLUT_ELAPSED_TIME);
	
	if(currentTime-oldTime > 1000)
	{
		fps = (frame*1000.0)/(currentTime - oldTime);
		oldTime = currentTime;
		//how long period is in frames; calculate when omega changes signs and multiple by 2
		frame = 0;
	}
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

void drawPeriod()
{
 //	std::cout << omega*prevOmega << std::endl;
        char *charString = (char*) malloc(12*sizeof(char));
        sprintf(charString, "Period: %.1f sec", period);
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        gluOrtho2D(0.0, WINDOW_HEIGHT, 0.0, WINDOW_HEIGHT);

        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();

        glColor3f(255, 255, 255);
        drawString(50, 75, GLUT_BITMAP_HELVETICA_12, charString);

        glPopMatrix();
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);

        free(charString);
}


void drawFPS()
{

	findFPS();

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
	drawString(50, 100, GLUT_BITMAP_HELVETICA_12, charString);

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	free(charString);
}

void drawFPP()
{
	findFPP();

        char *charString = (char*) malloc(12*sizeof(char));
        sprintf(charString, "FPP: %.0f", fpp);
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

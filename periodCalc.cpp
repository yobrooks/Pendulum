#include "openGl.h"
#include "prototypes.h"
#include "globals.h"
#include <iostream>
#include <stdio.h>

void findPeriod()
{
	if((prevOmega+omega) >= 0)
	{
		std::cout << "positive" << std::endl;
	}
	else
		std::cout<< "negative" << std::endl;
}

void drawPeriod()
{

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


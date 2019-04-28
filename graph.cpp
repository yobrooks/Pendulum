#ifndef GRAPH_CPP
#define GRAPH_CPP

#include "openGl.h"
#include "prototypes.h"
#include "globals.h"
#include <string.h>
#include <stdio.h>
void drawAxesLabels()
{
/*	#ifdef LIGHTING
	glDisable(GL_LIGHTING);
	#endif*/

	char *x = (char*) malloc(12*sizeof(char));
        char *y = (char*) malloc(12*sizeof(char));

	sprintf(x, "tetha");
        sprintf(y, "d(theta)/dt");

	glColor3f(0.0, 0.0, 0.0);

        drawString(675, 15, GLUT_BITMAP_HELVETICA_12, x);
        drawString(575, 300, GLUT_BITMAP_HELVETICA_12, y);
	
	free(x);
        free(y);
}

void drawAxes(int length)
{
        glPointSize(1.0);
        glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef((float)WINDOW_HEIGHT*0.71, (float)WINDOW_HEIGHT*0.39, 1.0);
	//x axis
        glBegin(GL_LINES);
                glVertex2i(length, -length-60);
                glVertex2i(0, -length-60);
        glEnd();

        glBegin(GL_LINES);
                glVertex2i(0, 0);
                glVertex2i(0, -length-60);
        glEnd();

	glPopMatrix();
}

void drawGraphScreen()
{
	glDisable(GL_LIGHTING);
	glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        gluOrtho2D(0.0, WINDOW_HEIGHT, 0.0, WINDOW_HEIGHT);

        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();
	
	drawAxes(225);

	drawAxesLabels();

	glColor3f(1.0, 1.0, 1.0);	
	glBegin(GL_POLYGON);
		glVertex2i(WINDOW_HEIGHT*.7, WINDOW_HEIGHT*.4);
		glVertex2i(WINDOW_HEIGHT*.7, 0);
		glVertex2i(WINDOW_HEIGHT, 0);
		glVertex2i(WINDOW_HEIGHT, WINDOW_HEIGHT*0.4);
	glEnd();


        glPopMatrix();
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);

	glEnable(GL_LIGHTING);
}

#endif

#ifndef GRAPH_CPP
#define GRAPH_CPP

#include "openGl.h"
#include "prototypes.h"
#include "globals.h"

/*void textToScreen(const char* message, float x, float y)
{
        char *charString = (char*) malloc(12*sizeof(char));
        sprintf(charString, message);
        glColor3ub(0, 0, 0);
        makeString(x, y, GLUT_BITMAP_TIMES_ROMAN_24, charString);
	free(charString);
}*/

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
	glColor3f(1.0, 1.0, 1.0);	
	glBegin(GL_POLYGON);
		glVertex2i(WINDOW_HEIGHT*.7, WINDOW_HEIGHT*.4);
		glVertex2i(WINDOW_HEIGHT*.7, 0);
		glVertex2i(WINDOW_HEIGHT, 0);
		glVertex2i(WINDOW_HEIGHT, WINDOW_HEIGHT*0.4);
	glEnd();

	drawAxes(5);
        //drawString(50, 100, GLUT_BITMAP_HELVETICA_12, charString);

        glPopMatrix();
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);

	glEnable(GL_LIGHTING);
}

#endif

void drawAxes(int length)
{
	glPointSize(1.0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
		glVertex2i(length, 0);
		glVertex2i(-length, 0);
	glEnd();

	glBegin(GL_LINES);
		glVertex2i(0, length);
		glVertex2i(0, -length);
	glEnd();
		
}

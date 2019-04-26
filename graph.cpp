#ifndef GRAPH_CPP
#define GRAPH_CPP

#include "openGl.h"
#include "prototypes.h"
#include "globals.h"
#include <string.h>
#include <stdio.h>
void drawAxesLabels()
{
	char x [] = "X-axis";
        char y [] = "Y-axis";
	int strnglngth;
/*	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
//	glTranslatef((float)WINDOW_HEIGHT*0.81, (float)WINDOW_HEIGHT*0.25, (float) 1);
	glTranslatef(100, 100, 0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
        glScalef(5.0f, 5.0f, 1.0f);
        strnglngth = (int) strlen(y);
        for(int i = 0; i < strnglngth; i++)
        {
                glutStrokeCharacter(GLUT_STROKE_ROMAN, y[i]);
        }
	glPopMatrix();*/
	
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef((float)WINDOW_HEIGHT*0.85, (float)WINDOW_HEIGHT*0.01, (float)1);
	glScalef(0.1f, 0.1f, 1.0f);
        strnglngth = (int) strlen(x);
        for(int i = 0; i < strnglngth; i++)
        {
                glutStrokeCharacter(GLUT_STROKE_ROMAN, x[i]);
        }

        glPopMatrix();

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

	//glRotatef(90, 0.0, 1.0, 1.0);
      //  drawStrokeText(WINDOW_HEIGHT*0.71, WINDOW_HEIGHT*0.35, 1, y);

        glPopMatrix();
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);

	glEnable(GL_LIGHTING);
}

#endif

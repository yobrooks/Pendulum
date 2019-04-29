#ifndef GRAPH_CPP
#define GRAPH_CPP

#include "openGl.h"
#include "prototypes.h"
#include "globals.h"
#include <string.h>
#include <stdio.h>

int count = 0;
std::vector<double> gPointsX;
std::vector<double> gPointsY;
void updatePoints(double ptheta, double pomega)
{

     if(gPointsX.size() < 2000 && gPointsY.size() < 2000)
     {
	gPointsX.push_back(ptheta);
     	gPointsY.push_back(pomega);
     }
     else{
	    gPointsX[count%2000] = ptheta;
	    gPointsY[count%2000] = pomega;
	 }

        count++;
	
	if(count == 2000)
	{
		count = 0;
	}

	//std::cout << A << std::endl;
}

void clearPoints()
{
	gPointsX.clear();
	gPointsY.clear();
	count = 0;	
}

void drawPoints()
{
	glPushMatrix();
	glColor3f(1.0, 0.2, 1.0);
	glBegin(GL_POINTS);
		for(int i = 0; i < gPointsX.size(); i++)
		{
			glVertex2d(gPointsX[i]*50+WINDOW_HEIGHT*0.85, gPointsY[i]*50+WINDOW_HEIGHT*0.20);
		}
	glEnd();
	glPopMatrix();
}

void drawAxesLabels()
{
/*	#ifdef LIGHTING
	glDisable(GL_LIGHTING);
	#endif*/

	char *x = (char*) malloc(12*sizeof(char));
        char *y = (char*) malloc(12*sizeof(char));

	sprintf(x, "theta");
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

	drawPoints();

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

#ifndef PROTOTYPES_H
#define PROTOTYPES_H

#include "openGl.h"
//function prototypes
void init();
void display();
void reshape(int , int);
void run();
double thetadot(double , double , double);
double omegadot(double , double , double);
void step(double*, double*, double*, double*  );
void findFPS();
void findPeriod();
void drawSphereColor();
void keyboard(unsigned char, int ,int);
void drawString(int x, int y, void *font, const char *string);
void drawScale();
void drawPeriod();
void glutLockFrameRate();
void askSynch(int, char**);
void defineWallsText();
void specialKeyboard(int,  int, int);
void drawRoomColor();
void drawSphereText();
void setSpotlight();
void drawGraphScreen();
GLuint loadTexture(const char* );
void drawAxes(int );
void updatePoints(double, double);
void kick();
void clearPoints();
#endif

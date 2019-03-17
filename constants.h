//global variables initial assignment

#include "Camera.h"
#include <math.h>

//int Nstep = 1000000;
const int WINDOW_HEIGHT = 500;
const int VIEWPORT_POS = 100;
int frame = 0;
int oldTime = 0;
double t = 0.0;
double omega = 0.0;
double theta = M_PI/4.0;
float fps = (float) 0.0;
double period=0;
double prevOmega = 0;
long int fpp=0;
float desiredFR;
float EYE_X = 15.0, EYE_Y =  0.0, EYE_Z = 0.0;
float CENTER_X = 0.0, CENTER_Y = 0.0, CENTER_Z = 0.0;


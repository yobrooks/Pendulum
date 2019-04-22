#ifndef GLOBALS_H
#define GLOBALS_H

#include "Camera.h"
#include <iostream>
#include <vector>

extern const int WINDOW_HEIGHT;
extern const int VIEWPORT_POS;
extern int frame;
extern int oldTime;
extern double theta;
extern double omega;
extern double t;
extern float fps;
extern double period;
extern double prevOmega;
extern long int fpp;
extern float desiredFR;
extern Camera camera;
extern std::vector<GLuint> textures;
extern bool graphOn;
#endif

#ifndef RESHAPE_CPP
#define RESHAPE_CPP

#include "openGl.h"
//reshape function given by Dr. Pounds
void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(40.0, (GLfloat) w/(GLfloat) h, 1.0, 40.0);
   glMatrixMode(GL_MODELVIEW);
}

#endif

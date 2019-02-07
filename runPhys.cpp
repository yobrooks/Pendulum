#include "openGl.h"
#include "prototypes.h"
#include "globals.h"
#include <stdio.h>
#include <math.h>

void run()
{

  // for (long i=0; i<2*Nstep; i++ ) {
     // printf("%f %f %f\n", t, theta, omega);
      step( &t, &theta, &omega, &prevOmega);
  // }

   glutPostRedisplay();
}

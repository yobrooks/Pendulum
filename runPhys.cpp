#include "openGl.h"
#include "prototypes.h"
#include "globals.h"
#include <stdio.h>
#include <math.h>

//idle func to run the physics engine
//code given by Dr. Pounds
void run()
{

  step( &t, &theta, &omega, &prevOmega);

   glutPostRedisplay();
}

#ifndef PENDMATH_CPP
#define PENDMATH_CPP

#include "prototypes.h"
#include "globals.h"
#include <stdio.h>
#include <math.h>
#include <vector>
//functions for the phsyics engine
//all functions provided by Dr. Pounds

int Nstep = 1000000;
double A = 0.0;

void kick()
{
	A = A+8;
}

double thetadot(double t, double theta, double omega)
{
   return omega;
}

double omegadot(double t, double theta, double omega)
{
   static double R = 1.00;  // Length of pendulum  (meters)
   static double g = 9.80;  // Normalized gravitational constant  (m/s^2)
   static double b = 0.02;  // Frictional damping constant
   static double m = 1.00;  // Mass in normalized gravitational units (kg)
 //  static double A = 0.00;  // Amplitude of initial driving force
   static double k = 0.00;  // Frequency parameter of initial driving force
	
   double num, denom;

   num = -b*omega + A*cos(k*t);
   denom = m*R*R;

 return (-g/R*sin(theta)+num)/denom;
}


void step(double *t, double *theta, double *omega, double *prevOmega )
{
   double dt, h;
   double k1, k2, k3, k4, j1, j2, j3, j4;
   h=10000.0/Nstep; 

    k1 = thetadot(*t, *theta, *omega);
    j1 = omegadot(*t, *theta, *omega);
    k2 = thetadot(*t+h/2, *theta+h/2*k1, *omega+h/2*j1);
    j2 = omegadot(*t+h/2, *theta+h/2*k1, *omega+h/2*j1);
    k3 = thetadot(*t+h/2, *theta+h/2*k2, *omega+h/2*j2);
    j3 = omegadot(*t+h/2, *theta+h/2*k2, *omega+h/2*j2);
    k4 = thetadot(*t+h, *theta+h*k3, *omega+h*j3);
    j4 = omegadot(*t+h, *theta+h*k3, *omega+h*j3);
    *theta = *theta + h/6*(k1+2*k2+2*k3+k4);
    *prevOmega=*omega; //sets previous omega before omega is updated
    *omega = *omega + h/6*(j1+2*j2+2*j3+j4);
    *t = *t + h;
//	updatePoints(theta, omega);
	//A = 0.0;
}


#endif

void run()
{
   double t=0.0;
   double theta=M_PI/4.0;
   double omega=0.0;

   for (long i=0; i<2*Nstep; i++ ) {
      printf("%f %f %f\n", t, theta, omega);
      step( &t, &theta, &omega);

}


//function prototypes
void init();
void display();
void reshape(int , int);
void run();
double thetadot(double , double , double);
double omegadot(double , double , double);
void step(double*, double*, double*, double*  );
//float findFPS();
void findFPS();
void findPeriod();
void drawSphere();
void keyboard(unsigned char, int ,int);
void drawStand();
void drawString(int x, int y, void *font, const char *string);
void drawFPS();
void drawScale();
void drawPeriod();
void glutSleep(int );
void findFPP();
void drawFPP();

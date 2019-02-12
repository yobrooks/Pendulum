
//function prototypes
void init();
void display();
void reshape(int , int);
void run();
double thetadot(double , double , double);
double omegadot(double , double , double);
void step(double*, double*, double*, double*  );
void findFPP();
void findFPS();
void findPeriod();
void drawSphere();
void keyboard(unsigned char, int ,int);
void drawStand();
void drawFPP();
void drawString(int x, int y, void *font, const char *string);
void drawFPS();
void drawScale();
void drawPeriod();
void glutLockFrameRate();
void askSynch(int, char**);

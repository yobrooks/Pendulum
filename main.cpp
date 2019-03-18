#include "openGl.h"
#include "prototypes.h"
#include "globals.h"
#include "constants.h"

int main(int argc, char** argv)
{
    askSynch(argc, argv); //figure out if synchonization needed based on command line argument
    glutInit(&argc, argv);
    glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH ); 
    glutInitWindowSize (WINDOW_HEIGHT, WINDOW_HEIGHT);
    glutInitWindowPosition (VIEWPORT_POS, VIEWPORT_POS);
    glutCreateWindow (argv[0]);
    glewInit();
    //init ();
    glClearColor(0.0,0.0,0.0,0.0);
    glLoadIdentity();
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutIdleFunc(run);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeyboard);
    glutMainLoop();
    return 0;
}


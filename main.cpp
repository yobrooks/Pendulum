#include "openGl.h"
#include "prototypes.h"
#include "globals.h"
#include "constants.h"

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH ); //change to double
    glutInitWindowSize (WINDOW_HEIGHT, WINDOW_HEIGHT);
    glutInitWindowPosition (VIEWPORT_POS, VIEWPORT_POS);
    glutCreateWindow (argv[0]);
    init ();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
    return 0;
}


#include "openGl.h"
#include "globals.h"
#include "Camera.h"
#include <iostream>


void specialKeyboard(int key, int x, int y)
{
	/*if(key == GLUT_KEY_PAGE_UP)
	{
		CAM_A = CAM_A - 0.1;
		
		if(CAM_A <=0){
			CAM_A = 0.0;	
		}
	}

	if(key == GLUT_KEY_PAGE_DOWN)
        {
                CAM_A = CAM_A + 0.1;

                if(CAM_A >=30){
                        CAM_A = 30.0;
                }
        }

	 if(key == GLUT_KEY_UP)
        {
                CAM_B = CAM_B - 1.0;
          
	        if(CAM_B < 0.0){
                        CAM_B = CAM_B + 360.0;
                }
        }

	if(key == GLUT_KEY_DOWN)
        {
                CAM_B = CAM_B + 1.0;

                if(CAM_B > 360.0){
                        CAM_B = CAM_B - 360.0;
                }
        }

	 if(key == GLUT_KEY_LEFT)
        {
                CAM_C = CAM_C - 1.0;
          
	        if(CAM_C < 0.0){
                	CAM_C = CAM_C + 360.0;
                }
        }

	 if(key == GLUT_KEY_RIGHT)
        {
                CAM_C = CAM_C + 1.0;

                if(CAM_C > 360){
                        CAM_C = CAM_C - 360.0;
                }
        }

	glutPostRedisplay();
}

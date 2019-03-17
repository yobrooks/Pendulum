
#include <math.h>
#include "Camera.h"

	//define public variables; three arrays that will hold the eye, center nad up positions for camera

	//float delta = 0.2;
	//Default Constructor; defines the initial values of the camera
	Camera::Camera()
	{
		eye[0] = 5.0, eye[1] = 0.0, eye[2] = 0.0;
		center[0] = 0.0, center[1] = 0.0, center [2] = 0.0;
		up[0] = 0.0, up[1] = 0.0, up[1] = 1.0;
	}

 	void Camera::translateXYZ(float num [], float dx, float dy, float dz)
                {
                        num[0] = num[0] + dx;
                        num[1] = num[1] + dy;
                        num[2] = num[2] + dz;
                }

                void Camera::rotateX(float num [], float changeX)
                {
                        num[1] = (cos(changeX) * num[1]) - (sin(changeX) * num[1]);
                        num[2] = (sin(changeX) * num[2]) + (cos(changeX) * num[2]);

                }

                void Camera::rotateY(float num [], float changeY)
                {
                         num[0] = (cos(changeY) * num[0]) + (sin(changeY) * num[0]);
                         num[2] = -(sin(changeY) * num[2]) + (cos(changeY) * num[2]);
                }

	  void Camera::rotateZ(float num [], float changeZ)
                {
                         num[0] = (cos(changeZ) * num[0]) - (sin(changeZ) * num[0]);
                         num[1] = (sin(changeZ) * num[1]) + (cos(changeZ) * num[1]);
                }

                void Camera::crossProd(float num1 [], float num2 [], float cross [])
                {
                        float result [3];
                        cross[0] = (num1[1] * num2[2]) - (num1[2] * num2 [1]);
                        cross[1] = (num1[2] * num2[0]) - (num1[0] * num2 [2]);
                        cross[2] = (num1[0] * num2[1]) - (num1[1] * num2 [0]);
                }

                void Camera::normalize(float num [])
                {
                        float length = sqrt((num[0] * num[0]) + (num[1] * num[1]) + (num[2] * num[2]));
                        num[0] = num[0]/length;
                        num[1] = num[1]/length;
                        num[2] = num[2]/length;
                }


	 void Camera::direction()
                {
                        forward[0] = center[0] - eye[0];
                        forward[1] = center[1] - eye[1];
                        forward[2] = center[2] - eye[2];
                        normalize(forward);
                }


	void Camera::moveForward()
	{
		direction();
		eye[0] = eye[0] + forward[0]  * delta;
		eye[1] = eye[1] + forward[1]  * delta;
		eye[2] = eye[2] + forward[2]  * delta;
		center[0] = center[0] + forward[0]  * delta;
		center[1] = center[1] + forward[1]  * delta;
		center[2] = center[2] + forward[2]  * delta;
		
	}
	
	void Camera::moveBackward()
	{
		direction();
		eye[0] = eye[0] - forward[0]  * delta;
		eye[1] = eye[1] - forward[1]  * delta;
		eye[2] = eye[2] - forward[2]  * delta;
		eye[0] = center[0] - forward[0]  * delta;
		eye[1] = center[1] - forward[1]  * delta;
		eye[2] = center[2] - forward[2]  * delta;
		
	}

	void Camera:: moveLeft()
	{
		direction();
		float result [3];
		crossProd(up, forward, result);		
		eye[0] = eye[0] - result[0] * delta;
		eye[1] = eye[1] - result[1] * delta;
		eye[2] = eye[2] - result[2] * delta;
		center[0] = center[0] - result[0] * delta;
		center[1] = center[1] - result[1] * delta;
		center[2] = center[2] - result[2] * delta;
	}

	void Camera::moveRight()
	{
		direction();
                float result [3];
		crossProd(up, forward, result);
                eye[0] = eye[0] + result[0] * delta;
                eye[1] = eye[1] + result[1] * delta;
                eye[2] = eye[2] + result[2] * delta;
                center[0] = center[0] + result[0] * delta;
                center[1] = center[1] + result[1] * delta;
                center[2] = center[2] + result[2] * delta;
	}

	void Camera::moveUp()
	{
		eye[2] = eye[2] + delta;
		center[2] = center[2] + delta;
	}

	void Camera::moveDown()
	{
		eye[2] = eye[2] - delta;
		center[2] = center[2] -delta;
	}
	
	//return camera to original values in initial constructor
	void Camera::returnOriginal()
	{
		eye[0] = 5.0, eye[1] = 0.0, eye[2] = 0.0;
                center[0] = 0.0, center[1] = 0.0, center [2] = 0.0;
                up[0] = 0.0, up[1] = 0.0, up[1] = 1.0;
	}

	


/*		void Camera::translateXYZ(float num [], float dx, float dy, float dz)
		{
			num[0] = num[0] + dx;
			num[1] = num[1] + dy;
			num[2] = num[2] + dz;	
		}

		void Camera::rotateX(float num [], float changeX)
		{
			num[1] = (cos(changeX) * num[1]) - (sin(changeX) * num[1]);
			num[2] = (sin(changeX) * num[2]) + (cos(changeX) * num[2]);
			
		}

		void Camera::rotateY(float num [], float changeY)
		{
			 num[0] = (cos(changeY) * num[0]) + (sin(changeY) * num[0]);
			 num[2] = -(sin(changeY) * num[2]) + (cos(changeY) * num[2]);
		}

		void Camera::rotateZ(float num [], float changeZ)
		{
			 num[0] = (cos(changeZ) * num[0]) - (sin(changeZ) * num[0]);
			 num[1] = (sin(changeZ) * num[1]) + (cos(changeZ) * num[1]);
		}
		
		void Camera::crossProd(float num1 [], float num2 [], float cross [])
		{
			float result [3];
			cross[0] = (num1[1] * num2[2]) - (num1[2] * num2 [1]);
			cross[1] = (num1[2] * num2[0]) - (num1[0] * num2 [2]);
			cross[2] = (num1[0] * num2[1]) - (num1[1] * num2 [0]);
		}

		void Camera::normalize(float num [])
		{
			float length = sqrt((num[0] * num[0]) + (num[1] * num[1]) + (num[2] * num[2]));
			num[0] = num[0]/length;
			num[1] = num[1]/length;
			num[2] = num[2]/length;
		}

		void Camera::direction()	
		{
			forward[0] = center[0] - eye[0];
			forward[1] = center[1] - eye[1];
			forward[2] = center[2] - eye[2];		
			normalize(forward);
		}*/


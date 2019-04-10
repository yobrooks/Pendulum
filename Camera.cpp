#ifndef CAMERA_CPP
#define CAMERA_CPP
#include <math.h>
#include <algorithm>
#include <iostream>
#include <iterator>
#include "Camera.h"

	//define public variables; three arrays that will hold the eye, center nad up positions for camera

	//Default Constructor; defines the initial values of the camera
	Camera::Camera()
	{
		eye[0] = 10.0, eye[1] = 0.0, eye[2] = 0.0;
		center[0] = 0.0, center[1] = 0.0, center [2] = 0.0;
		up[0] = 0.0, up[1] = 0.0, up[2] = 1.0;
	}
	
		// 			    *Private functions*				//
			

		//translate array by change in x, y or z
 	  	void Camera::translateXYZ(float num [], float dx, float dy, float dz)
                {
                        num[0] = num[0] + dx;
                        num[1] = num[1] + dy;
                        num[2] = num[2] + dz;
                }

		//rotation about x axis
                void Camera::rotateX(float num [], float changeX)
                {
                        num[1] = (cos(changeX) * num[1]) - (sin(changeX) * num[2]);
                        num[2] = (sin(changeX) * num[1]) + (cos(changeX) * num[2]);

                }

		//rotate about y axis
                void Camera::rotateY(float num [], float changeY)
                {
                         num[0] = (cos(changeY) * num[0]) + (sin(changeY) * num[2]);
                         num[2] = -(sin(changeY) * num[0]) + (cos(changeY) * num[2]);
                }

		//rotation about z axis
	  	void Camera::rotateZ(float num [], float changeZ)
                {
                         num[0] = (cos(changeZ) * num[0]) - (sin(changeZ) * num[1]);
                         num[1] = (sin(changeZ) * num[0]) + (cos(changeZ) * num[1]);
                }

		//compute the cross products of two vectors
                void Camera::crossProd(float num1 [], float num2 [], float cross [])
                {
                        float result [3];
                        cross[0] = (num1[1] * num2[2]) - (num1[2] * num2 [1]);
                        cross[1] = (num1[2] * num2[0]) - (num1[0] * num2 [2]);
                        cross[2] = (num1[0] * num2[1]) - (num1[1] * num2 [0]);
                }

		//normalize a vector by making it 1 in length
                void Camera::normalize(float num [])
                {
                        float length = sqrt((num[0] * num[0]) + (num[1] * num[1]) + (num[2] * num[2]));
                        num[0] = num[0]/length;
                        num[1] = num[1]/length;
                        num[2] = num[2]/length;
                }
	
	
		//function to check for collisions
		//returns true if there is a collision and false if there is not
		bool Camera::checkForCollisions(float colEye[], float colCen[])
		{
			float tempEye[3]; float tempCenter[3];
			std::copy(colEye, colEye+3, tempEye); std::copy(colCen, colCen+3, tempCenter);
			bool result = false;
		//changes negative cooridnate to positive
		for(int i = 0; i < 2; i++)
		{
			if(tempEye[i] <0.0)
			{
				tempEye[i] = tempEye[i] * (-1.0);
			}
		}
	
		if(tempCenter[2] <= -5.6 || tempCenter[2] >= 3.6)
		{
			result = true;
		}else{
			if((11.0 - tempEye[0]) < 0.5 || (11.0 - tempEye[1]) <0.5)
                        {
                                result =  true;
                        }
                        else{
                                result = false;
                            }
		}
		//std::cout << result << std::endl;
		return result;	
	}

	//function to compute the forward direction vector of the camera
  	 void Camera::direction(float point [])
         {
		forward[0] = center[0] - point[0];
                forward[1] = center[1] - point[1];
                forward[2] = center[2] - point[2];
                normalize(forward);
         }

	//										//
	//					*Public Functions*			//

	//function to move camera position forward
	void Camera::moveForward(float delta)
	{
		float tempEye[3]; float tempCenter[3];
		std::copy(eye, eye+3, tempEye); std::copy(center, center+3, tempCenter);
		direction(tempEye);

		tempEye[0] = tempEye[0] + forward[0]  * delta;
		tempEye[1] = tempEye[1] + forward[1]  * delta;
		tempEye[2] = tempEye[2] + forward[2]  * delta;
		tempCenter[0] = tempCenter[0] + forward[0]  * delta;
		tempCenter[1] = tempCenter[1] + forward[1]  * delta;
		tempCenter[2] = tempCenter[2] + forward[2]  * delta;
		
		if(checkForCollisions(tempEye, tempCenter) == false)
		{
			std::copy(tempEye, tempEye+3, eye);
			std::copy(tempCenter, tempCenter+3, center);
		}	
	}
	
	//function to move camera positino backwards
	void Camera::moveBackward(float delta)
	{
		 float tempEye[3]; float tempCenter[3];
                std::copy(eye, eye+3, tempEye); std::copy(center, center+3, tempCenter);
                direction(tempEye);

                tempEye[0] = tempEye[0] - forward[0]  * delta;
                tempEye[1] = tempEye[1] - forward[1]  * delta;
                tempEye[2] = tempEye[2] - forward[2]  * delta;
                tempCenter[0] = tempCenter[0] - forward[0]  * delta;
                tempCenter[1] = tempCenter[1] - forward[1]  * delta;
                tempCenter[2] = tempCenter[2] - forward[2]  * delta;

                if(checkForCollisions(tempEye, tempCenter) == false)
                {
                        std::copy(tempEye, tempEye+3, eye);
                        std::copy(tempCenter, tempCenter+3, center);
                }

	}

	//functino to move camera position left
	void Camera:: moveLeft(float delta)
	{
		float tempEye [3]; float tempCenter[3];
		std::copy(eye, eye+3, tempEye); std::copy(center, center+3, tempCenter);
		direction(tempEye);
		float result [3];
		crossProd(up, forward, result);	
		
		tempEye[0] = tempEye[0] + result[0] * delta;
		tempEye[1] = tempEye[1] + result[1] * delta;
		tempEye[2] = tempEye[2] + result[2] * delta;
		tempCenter[0] = tempCenter[0] + result[0] * delta;
		tempCenter[1] = tempCenter[1] + result[1] * delta;
		tempCenter[2] = tempCenter[2] + result[2] * delta;

		if(checkForCollisions(tempEye, tempCenter) == false)
                {
                        std::copy(tempEye, tempEye+3, eye);
			std::copy(tempCenter, tempCenter+3, center);
                }
	}


	//function to move camera position right
	void Camera::moveRight(float delta)
	{
		float tempEye [3]; float tempCenter[3];
                std::copy(eye, eye+3, tempEye); std::copy(center, center+3, tempCenter);
                direction(tempEye);
                float result [3];
                crossProd(up, forward, result);

                tempEye[0] = tempEye[0] - result[0] * delta;
                tempEye[1] = tempEye[1] - result[1] * delta;
                tempEye[2] = tempEye[2] - result[2] * delta;
                tempCenter[0] = tempCenter[0] - result[0] * delta;
                tempCenter[1] = tempCenter[1] - result[1] * delta;
                tempCenter[2] = tempCenter[2] - result[2] * delta;

                if(checkForCollisions(tempEye, tempCenter) == false)
                {
                        std::copy(tempEye, tempEye+3, eye);
                        std::copy(tempCenter, tempCenter+3, center);
                }

		
		/*float temp [3];
		std::copy(eye, eye+3, temp);
		direction(temp);
                float result [3];
		crossProd(up, forward, result);
                temp[0] = temp[0] - result[0] * delta;
                temp[1] = temp[1] - result[1] * delta;
                temp[2] = temp[2] - result[2] * delta;
                center[0] = center[0] - result[0] * delta;
                center[1] = center[1] - result[1] * delta;
                center[2] = center[2] - result[2] * delta;

		if(checkForCollisions(temp) == false)
                {
                        std::copy(temp, temp+3, eye);
                }*/
	}

	//function to move camera position up
	void Camera::moveUp(float delta)
	{
		float tempEye [3]; float tempCenter[3];
                std::copy(eye, eye+3, tempEye); std::copy(center, center+3, tempCenter);
                direction(tempEye);
                float result [3];
                crossProd(up, forward, result);

                tempEye[2] = tempEye[2] + delta;
                tempCenter[2] = tempCenter[2] + delta;
		
                if(checkForCollisions(tempEye, tempCenter) == false)
                {
                        std::copy(tempEye, tempEye+3, eye);
                        std::copy(tempCenter, tempCenter+3, center);
                }

	/*	float temp [3];
                std::copy(eye, eye+3, temp);
			
		temp[2] = temp[2] + delta;
		center[2] = center[2] + delta;

		 if(checkForCollisions(temp) == false)
                {
                        std::copy(temp, temp+3, eye);
                }*/

	}

	//function to move camera position down
	void Camera::moveDown(float delta)
	{
		/*float temp [3];
                std::copy(eye, eye+3, temp);

		temp[2] = temp[2] - delta;
		center[2] = center[2] -delta;

		 if(checkForCollisions(temp) == false)
                {
                        std::copy(temp, temp+3, eye);
                }*/

		float tempEye [3]; float tempCenter[3];
                std::copy(eye, eye+3, tempEye); std::copy(center, center+3, tempCenter);
                direction(tempEye);
                float result [3];
                crossProd(up, forward, result);

                tempEye[2] = tempEye[2] - delta;
                tempCenter[2] = tempCenter[2] - delta;

                if(checkForCollisions(tempEye, tempCenter) == false)
                {
                        std::copy(tempEye, tempEye+3, eye);
                        std::copy(tempCenter, tempCenter+3, center);
                }


	}
	
	//pan camera left 
	void Camera::panLeft(float delta)
	{
		float temp [3];
		std::copy(eye, eye+3, temp);
		
		translateXYZ(eye, -temp[0], -temp[1], -temp[2]);
		translateXYZ(center, -temp[0], -temp[1], -temp[2]);

		rotateZ(eye, delta);
		rotateZ(center, delta);
		
		translateXYZ(eye, temp[0], temp[1], temp[2]);
                translateXYZ(center, temp[0], temp[1], temp[2]);			
	}

	//pan camera right
	void Camera::panRight(float delta)
	{
		float temp [3];
                std::copy(eye, eye+3, temp);
                translateXYZ(eye, -temp[0], -temp[1], -temp[2]);
                translateXYZ(center, -temp[0], -temp[1], -temp[2]);

                rotateZ(eye, -delta);
                rotateZ(center, -delta);

                translateXYZ(eye, temp[0], temp[1], temp[2]);
                translateXYZ(center, temp[0], temp[1], temp[2]);

	}

	//pan camera up
	void Camera::panUp(float delta)
	{
		float temp [3];
                std::copy(eye, eye+3, temp);

                translateXYZ(eye, -temp[0], -temp[1], -temp[2]);
                translateXYZ(center, -temp[0], -temp[1], -temp[2]);

                rotateY(eye, delta);
                rotateY(center, delta);

                translateXYZ(eye, temp[0], temp[1], temp[2]);
                translateXYZ(center, temp[0], temp[1], temp[2]);
	}

	//pan camera down
	void Camera::panDown(float delta)
	{
		float temp [3];
                std::copy(eye, eye+3, temp);

                translateXYZ(eye, -temp[0], -temp[1], -temp[2]);
                translateXYZ(center, -temp[0], -temp[1], -temp[2]);

                rotateY(eye, -delta);
                rotateY(center, -delta);

                translateXYZ(eye, temp[0], temp[1], temp[2]);
                translateXYZ(center, temp[0], temp[1], temp[2]);
	}
	//return camera to original values in initial constructor
	void Camera::returnOriginal()
	{
		eye[0] = 10.0, eye[1] = 0.0, eye[2] = 0.0;
                center[0] = 0.0, center[1] = 0.0, center [2] = 0.0;
                up[0] = 0.0, up[1] = 0.0, up[2] = 1.0;
	}

	
#endif

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
	
	//private function to check for collisions
	//returns true if there is a collision and false if there is not
	 bool Camera::checkForCollisions(float camera[])
	{
		float temp [3];
		std::copy(camera, camera+3, temp);
		//changes negative cooridnate to positive
		if(temp[0] < 0)
		{
			temp[0] = temp[0] * (-1.0);
		}

		if(temp[1] < 0.0)
		{
			temp[1] = temp[1] * (-1.0);
		}

		//if the camera's z position is between -6 and 4 then move on to next check point
		if(temp[2] > -6.0 && temp[2] < 4.0)
		{
			//if camera's x or y values have a distance less than 0.5 to 15 then return true
			if((13.0 - temp[0]) < 0.5 || (13.0 - temp[1]) <0.5)
			{
				return true;
			}
			//else if camera's x or y distance to 15 is greater than 0.5 return false
			else{ 
				return false;
			}
		}
		else{ 
			return true;
		}
	}

	 void Camera::direction(float point [])
                {
                        forward[0] = center[0] - point[0];
                        forward[1] = center[1] - point[1];
                        forward[2] = center[2] - point[2];
                        normalize(forward);
                }


	void Camera::moveForward(float delta)
	{
		float temp [3];
		std::copy(eye, eye+3, temp);	
		direction(temp);
		temp[0] = temp[0] + forward[0]  * delta;
		temp[1] = temp[1] + forward[1]  * delta;
		temp[2] = temp[2] + forward[2]  * delta;
		center[0] = center[0] + forward[0]  * delta;
		center[1] = center[1] + forward[1]  * delta;
		center[2] = center[2] + forward[2]  * delta;
		
		if(checkForCollisions(temp) == false)
		{
			std::copy(temp, temp+3, eye);
		}
		
	}
	
	void Camera::moveBackward(float delta)
	{
		float temp [3];
		std::copy(eye, eye+3, temp);
		direction(temp);
		temp[0] = temp[0] - forward[0]  * delta;
		temp[1] = temp[1] - forward[1]  * delta;
		temp[2] = temp[2] - forward[2]  * delta;
		center[0] = center[0] - forward[0]  * delta;
		center[1] = center[1] - forward[1]  * delta;
		center[2] = center[2] - forward[2]  * delta;
		
		if(checkForCollisions(temp) == false)
                {
                        std::copy(temp, temp+3, eye);
                }

	}

	void Camera:: moveLeft(float delta)
	{
		float temp [3];
		std::copy(eye, eye+3, temp);
		direction(temp);
		float result [3];
		crossProd(up, forward, result);		
		temp[0] = temp[0] + result[0] * delta;
		temp[1] = temp[1] + result[1] * delta;
		temp[2] = temp[2] + result[2] * delta;
		center[0] = center[0] + result[0] * delta;
		center[1] = center[1] + result[1] * delta;
		center[2] = center[2] + result[2] * delta;

		if(checkForCollisions(temp) == false)
                {
                        std::copy(temp, temp+3, eye);
                }

	}

	void Camera::moveRight(float delta)
	{
		float temp [3];
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
                }

	}

	void Camera::moveUp(float delta)
	{
		eye[2] = eye[2] + delta;
		center[2] = center[2] + delta;
	}

	void Camera::moveDown(float delta)
	{
		eye[2] = eye[2] - delta;
		center[2] = center[2] -delta;
	}
	
	//return camera to original values in initial constructor
	void Camera::returnOriginal()
	{
		eye[0] = 5.0, eye[1] = 0.0, eye[2] = 0.0;
                center[0] = 0.0, center[1] = 0.0, center [2] = 0.0;
                up[0] = 0.0, up[1] = 0.0, up[2] = 1.0;
	}

	
#endif

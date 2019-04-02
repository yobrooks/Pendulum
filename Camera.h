#ifndef CAMERA_H
#define CAMERA_H

#include "math.h"

	//class Camera;

	class Camera{
	 private:
                float delta;
                float forward [3];
                void translateXYZ(float num [], float dx, float dy, float dz);
                void rotateX(float num [], float changeX);
                        void rotateY(float num [], float changeY);
                void rotateZ(float num [], float changeZ);
                void crossProd(float num1 [], float num2 [], float cross[]);
		void normalize(float num []);
                void direction();


	public:
		float eye [3];
		float center [3];
		float up [3];
		Camera();
		void moveForward();
		void moveBackward();
		void moveLeft();
		void moveRight();
		void moveUp();
		void moveDown();
		void returnOriginal();
		
};

#endif





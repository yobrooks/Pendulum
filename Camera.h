#ifndef CAMERA_H
#define CAMERA_H

#include "math.h"

	//class Camera;

	class Camera{
	 private:
                float forward [3];
                void translateXYZ(float num [], float dx, float dy, float dz);
                void rotateX(float num [], float changeX);
                        void rotateY(float num [], float changeY);
                void rotateZ(float num [], float changeZ);
                void crossProd(float num1 [], float num2 [], float cross[]);
		void normalize(float num []);
                void direction(float point []);
		bool checkForCollisions(float colEye[], float colCen[]);

	public:
		float eye [3];
		float center [3];
		float up [3];
		Camera();
		void moveForward(float delta);
		void moveBackward(float delta);
		void moveLeft(float delta);
		void moveRight(float delta);
		void moveUp(float delta);
		void moveDown(float delta);
		void panLeft(float delta);
		void panRight(float delta);
		void panUp(float delta);
		void panDown(float delta);
		void returnOriginal();
		
};

#endif





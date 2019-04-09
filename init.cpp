#ifndef INIT_CPP
#define INIT_CPP

#include "openGl.h"
#include "globals.h"
#include "Camera.h"
#include "prototypes.h"
#include <iostream>
#include <vector>

//initialize vector of textures
std::vector<GLuint> textures;
GLfloat lightPos[] = {5.0, 0.0, 5.0, 1.0};
GLfloat lightDifOne[] = {0.0, 0.0, 1.0, 1.0};
GLfloat lightAmbOne[] ={0.0, 0.0, 1.0, 0.6};
void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glLoadIdentity();

   	//load textures and put them into vector for later use
    GLuint tex1 = loadTexture("./textures/wall 6.jpg"); textures.push_back(tex1);
    GLuint tex2 = loadTexture("./textures/floor1.jpg"); textures.push_back(tex2);
    GLuint tex3 = loadTexture("./textures/wall 6.jpg"); textures.push_back(tex3);
    GLuint tex4 = loadTexture("./textures/wall 2.jpg"); textures.push_back(tex4);
    GLuint tex5 = loadTexture("./textures/wall 6.jpg"); textures.push_back(tex5);
    GLuint tex6 = loadTexture("./textures/wall 6.jpg"); textures.push_back(tex6);
    GLuint tex7 = loadTexture("./textures/disco ball.jpg"); textures.push_back(tex7);
    GLuint tex8 = loadTexture("./textures/cord.jpg"); textures.push_back(tex8);

	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDifOne);
        glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmbOne);
        glLightfv(GL_LIGHT1, GL_SPECULAR, lightDifOne);

}

#endif

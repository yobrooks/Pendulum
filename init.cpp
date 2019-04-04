#include "openGl.h"
#include "globals.h"
#include "Camera.h"
#include "prototypes.h"
#include <iostream>
#include <vector>

std::vector<GLuint> textures;
void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glLoadIdentity();
    //Camera camera;  
    //std::vector<GLuint> textures;
    GLuint tex1 = loadTexture("./textures/wall 6.jpg"); textures.push_back(tex1);
    GLuint tex2 = loadTexture("./textures/floor1.jpg"); textures.push_back(tex2);
    GLuint tex3 = loadTexture("./textures/wall 6.jpg"); textures.push_back(tex3);
    GLuint tex4 = loadTexture("./textures/wall 2.jpg"); textures.push_back(tex4);
    GLuint tex5 = loadTexture("./textures/wall 6.jpg"); textures.push_back(tex5);
    GLuint tex6 = loadTexture("./textures/wall 6.jpg"); textures.push_back(tex6);
    GLuint tex7 = loadTexture("./textures/disco ball.jpg"); textures.push_back(tex7);
    GLuint tex8 = loadTexture("./textures/cord.jpg"); textures.push_back(tex8);
   // std::vector<GLuint> textures{tex1, tex2, tex3, tex4, tex5, tex6, tex7, tex8};   
}


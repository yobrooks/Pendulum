#ifndef TEXTURES_CPP
#define TEXTURES_CPP

#include "openGl.h"
#include "SOIL.h"

//load texture method to create a texture that will later be stored in a vector
//returns texture ID for later use
GLuint loadTexture(const char* fileName)
{
	unsigned char* image;
	int height, width;
	GLuint texID;

   	glGenTextures(1, &texID);  
    	glBindTexture(GL_TEXTURE_2D, texID); 

   	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    	image = SOIL_load_image(fileName, &width, &height, 0, SOIL_LOAD_RGB); 
    	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);	

	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);

	return texID;
}

#endif

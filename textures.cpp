#include "openGl.h"
#include "SOIL.h"
#include <string>
#include "structs.h"

Texture assignTexVals()
{
	Texture temp;
	temp.texID = 
	temp.width = 
	temp.height = 
	temp.imageExt = 
	return temp;
}

void bind()
{
	glGenTextures(count, &myTex);
	glBindTexture(GL_TEXTURE_2D, myTex);
}

void setFilters()
{
	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
 //   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}


void loadTexture(const char* name)
{
	unsigned char* tempImage = SOIL_load_image(name, &width, &height, NULL, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipMap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	
}

void drawTextures()
{
	glBegin(GL_POLYGON);

      glTexCoord2d( 0.0, 0.0);   glVertex2d(  0.0,  0.0 );
      glTexCoord2d( 0.0, 1.0);   glVertex2d(  0.0, 10.0 );
      glTexCoord2d( 1.0, 1.0);   glVertex2d( 10.0, 10.0 );
      glTexCoord2d( 1.0, 0.0);   glVertex2d( 10.0,  0.0 );

    glEnd();
}


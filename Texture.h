#include "openGl.h"
#include "SOIL.h"


class Texture{

	private: GLuint texID;
		 int width;
		 int height;

	public: Texture(const char* fileName);
		GLuint getID();

};


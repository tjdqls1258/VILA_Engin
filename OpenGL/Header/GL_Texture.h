#ifndef GL_TEXTURE_H_
#define GL_TEXTURE_H_

#include <Windows.h>
#include<iostream>
#include<string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL2/SOIL2.h>

#include "Interface/ITexture.h"

class Texture : public ITexture
{
private:
	GLuint id;
	int width = 0;
	int height = 0;
	unsigned int type;

public:
	Texture(const char* fileName);
	~Texture();
	inline const GLuint& getID();
	void bind(const GLint& texture_unit);
	void unbind();
	void loadFromFile(const char* fileName);
};

#endif // !GL_TEXTURE_H_

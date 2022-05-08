#include "OpenGL/Header/GL_Texture.h"

Texture::Texture(const char* fileName) : ITexture(fileName)
{
	this->type = GL_TEXTURE_2D;

	unsigned char* image = SOIL_load_image(fileName, &this->width, &this->height, NULL, SOIL_LOAD_RGBA);
	glGenTextures(1, &this->id);
	glBindTexture(GL_TEXTURE_2D, this->id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); //U
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); //V
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	if (image)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "ERROR::TEXTURE::TEXTURE_LOADING_FAILED: " << fileName << "\n";
	}

	SOIL_free_image_data(image);
	glActiveTexture(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

Texture::~Texture()
{
	glDeleteTextures(1, &this->id);
}

inline const GLuint& Texture::getID()
{
	return this->id; 
}

void Texture::bind(const GLint& texture_unit)
{
	glActiveTexture(GL_TEXTURE0 + texture_unit);
	glBindTexture(this->type, this->id);
}

void Texture::unbind()
{
	glActiveTexture(0);
	glBindTexture(this->type, 0);
}

void Texture::loadFromFile(const char* fileName)
{
	if (this->id)
	{
		glDeleteTextures(1, &this->id);
	}

	unsigned char* image = SOIL_load_image(fileName, &this->width, &this->height, NULL, SOIL_LOAD_RGBA);

	glGenTextures(1, &this->id);
	glBindTexture(this->type, this->id);

	glTexParameteri(this->type, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(this->type, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(this->type, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(this->type, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	if (image)
	{
		glTexImage2D(this->type, 0, GL_RGBA, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
		glGenerateMipmap(this->type);
	}
	else
	{
		std::cout << "ERROR::TEXTURE::LOADFROMFILE::TEXTURE_LOADING_FAILED: " << fileName << "\n";
	}

	glActiveTexture(0);
	glBindTexture(this->type, 0);
	SOIL_free_image_data(image);
}
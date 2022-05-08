#include "Create_OpenGL.h"

IRender* Create_OpenGL::createRender()
{
	return new Reander_OpenGL(title, WINDOW_WIDTH, WINDOW_HEIGHT, GL_VERSION_MAJOR, GL_VERSION_MINOR, true, Windows_color);
}

Create_OpenGL::Create_OpenGL(const char* title, const int WINDOW_WIDTH, const int WINDOW_HEIGHT,
	glm::vec4 Windows_color, 
	const int GL_VERSION_MAJOR, const int GL_VERSION_MINOR) :
	WINDOW_WIDTH(WINDOW_WIDTH), WINDOW_HEIGHT(WINDOW_HEIGHT),
	Windows_color(Windows_color),
	GL_VERSION_MAJOR(GL_VERSION_MAJOR), GL_VERSION_MINOR(GL_VERSION_MINOR)
{
	this->title = title;
}
#ifndef CREATE_OPENGL_H_
#define CREATE_OPENGL_H_

#include "Interface/ICreate_Render.h"
#include "OpenGL/Header/Reander_Opengl.h"

class Create_OpenGL : public ICreate_Render
{
private:
	const char* title;
	const int WINDOW_WIDTH;
	const int WINDOW_HEIGHT;
	const int GL_VERSION_MAJOR; 
	const int GL_VERSION_MINOR; 
	glm::vec4 Windows_color;

	IRender* createRender() override;
public: 
	Create_OpenGL(const char* title, const int WINDOW_WIDTH, const int WINDOW_HEIGHT, 
		glm::vec4 Windows_color = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f),
		const int GL_VERSION_MAJOR = 4, const int GL_VERSION_MINOR = 4);
};

#endif // !CREATE_OPENGL_H_

#ifndef GL_VERTEX_H_
#define GL_VERTEX_H_

#include <Windows.h>
#include <glm/glm.hpp>

struct Vertex
{
	glm::vec3 position;
	glm::vec3 color;
	glm::vec2 texcoord;
	glm::vec3 normal;
};

#endif // !GL_VERTEX_H_

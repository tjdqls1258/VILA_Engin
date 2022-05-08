#ifndef GL_MESHDATA_H_
#define GL_MESHDATA_H_

#include <Windows.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <vector>
#include "GL_Vertex.h"

class Primitive
{
private:
	std::vector<GLuint> indices;
	std::vector<Vertex> vertices;
public:
	Primitive() {}
	virtual ~Primitive() {}

	//Functions
	void set(const Vertex* vertices, const unsigned nrOfVertices,
		const GLuint* indices, const unsigned nrOfIndices);

	inline Vertex* getVertices()
	{
		return this->vertices.data();
	}
	inline GLuint* getIndices()
	{
		return this->indices.data();
	}
	inline const unsigned getNrOfVertices()
	{
		return this->vertices.size();
	}
	inline const unsigned getNrOfIndices()
	{
		return this->indices.size();
	}
};

class Triangle : public Primitive
{
public:
	Triangle() : Primitive()
	{
		Vertex vertices[] =
		{
				//Position								//Color							//Texcoords					//Normals
	/*0*/		glm::vec3(0.f, 0.5f, 0.f),				glm::vec3(1.f, 0.f, 0.f),		glm::vec2(0.5f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
	/*1*/		glm::vec3(-0.5f, -0.5f, 0.f),			glm::vec3(0.f, 1.f, 0.f),		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
	/*2*/		glm::vec3(0.5f, -0.5f, 0.f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
		};
	
		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex); // 3

		GLuint indices[] =
		{
			0, 1, 2	//Triangle 1
		};
		unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint); // 3
		this->set(vertices, nrOfVertices, indices, nrOfIndices);
	}
};

class Quad : public Primitive
{
public:
	Quad() : Primitive()
	{
		Vertex vertices[] =
		{
				//Position								//Color							//Texcoords					//Normals
	/*0*/		glm::vec3(-0.5f, 0.5f, 0.f),			glm::vec3(1.f, 0.f, 0.f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f), //
	/*1*/		glm::vec3(-0.5f, -0.5f, 0.f),			glm::vec3(0.f, 1.f, 0.f),		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f), //
	/*2*/		glm::vec3(0.5f, -0.5f, 0.f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f), //
	/*3*/		glm::vec3(0.5f, 0.5f, 0.f),				glm::vec3(1.f, 1.f, 0.f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f)  //
		};
		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex); //4 
		
		GLuint indices[] =
		{
			0, 1, 2,	//Triangle 1
			0, 2, 3		//Triangle 2
		};
		unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint); //6
		this->set(vertices, nrOfVertices, indices, nrOfIndices);
	}
};

class Pyramid : public Primitive
{
public:
	Pyramid() : Primitive()
	{
		Vertex vertices[] =
		{
			//Position								//Color							//Texcoords					//Normals
			//Triangle front
			glm::vec3(0.f, 0.5f, 0.f),				glm::vec3(1.f, 0.f, 0.f),		glm::vec2(0.5f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.5f, -0.5f, 0.5f),			glm::vec3(0.f, 1.f, 0.f),		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.5f, -0.5f, 0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),

			//Triangle left
			glm::vec3(0.f, 0.5f, 0.f),				glm::vec3(1.f, 1.f, 0.f),		glm::vec2(0.5f, 1.f),		glm::vec3(-1.f, 0.f, 0.f),
			glm::vec3(-0.5f, -0.5f, -0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(0.f, 0.f),		glm::vec3(-1.f, 0.f, 0.f),
			glm::vec3(-0.5f, -0.5f, 0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(-1.f, 0.f, 0.f),

			//Triangle back
			glm::vec3(0.f, 0.5f, 0.f),				glm::vec3(1.f, 1.f, 0.f),		glm::vec2(0.5f, 1.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.5f, -0.5f, -0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.5f, -0.5f, -0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),

			//Triangles right
			glm::vec3(0.f, 0.5f, 0.f),				glm::vec3(1.f, 1.f, 0.f),		glm::vec2(0.5f, 1.f),		glm::vec3(1.f, 0.f, 0.f),
			glm::vec3(0.5f, -0.5f, 0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(0.f, 0.f),		glm::vec3(1.f, 0.f, 0.f),
			glm::vec3(0.5f, -0.5f, -0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(1.f, 0.f, 0.f),
		};
		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		this->set(vertices, nrOfVertices, nullptr, 0);
	}
};

class Cube : public Primitive
{
public:
	Cube() : Primitive()
	{
		Vertex vertices[] =
		{
			//Position								//Color							//Texcoords					//Normals
			glm::vec3(-0.5f, 0.5f, 0.5f),			glm::vec3(1.f, 0.f, 0.f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.5f, -0.5f, 0.5f),			glm::vec3(0.f, 1.f, 0.f),		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.5f, -0.5f, 0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.5f, 0.5f, 0.5f),			glm::vec3(1.f, 1.f, 0.f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(0.5f, 0.5f, -0.5f),			glm::vec3(1.f, 0.f, 0.f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.5f, -0.5f, -0.5f),			glm::vec3(0.f, 1.f, 0.f),		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.5f, -0.5f, -0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.5f, 0.5f, -0.5f),			glm::vec3(1.f, 1.f, 0.f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, -1.f),
		};
		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		GLuint indices[] =
		{
			0, 1, 2,
			0, 2, 3,

			7, 6, 1,
			7, 1, 0,

			4, 5, 6,
			4, 6, 7,

			3, 2, 5,
			3, 5, 4,

			1, 6, 5,
			1, 5, 2,

			0, 3, 4,
			0, 4, 7
		};
		unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

		this->set(vertices, nrOfVertices, indices, nrOfIndices);
	}
};

#endif // !GL_MESHDATA_H_
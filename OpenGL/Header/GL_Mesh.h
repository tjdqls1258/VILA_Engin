#ifndef GL_MESH_H_
#define GL_MESH_H_

#include <iostream>
#include <vector>

#include "GL_Vertex.h"
#include "GL_MeshData.h"
#include "GL_Shader.h"
#include "GL_Texture.h"
#include "GL_Material.h"
#include "Interface/IMesh.h"

class Mesh : public IMesh
{
private:
	Vertex* vertexArray;
	unsigned nrOfVertices;
	GLuint* indexArray;
	unsigned nrOfIndices;

	GLuint VAO;
	GLuint VBO;
	GLuint EBO;

	glm::vec3 position;
	glm::vec3 origin;
	glm::vec3 rotation;
	glm::vec3 self_rotation;
	glm::vec3 scale;
	glm::mat4 ModelMatrix;
	glm::mat4 selfModeMatrix;

	void initVAO();
	void updateUniforms(Shader* shader);
	void updateModelMatrix();

public:
	Mesh(Vertex* vertexArray,const unsigned& nrOfVertices, GLuint* indexArray, const unsigned& nrOfIndices, 
		glm::vec3 position = glm::vec3(0.f), glm::vec3 origin = glm::vec3(0.f),
		glm::vec3 rotation = glm::vec3(0.f), glm::vec3 scale = glm::vec3(1.f));
	Mesh(Primitive* primitive,
		glm::vec3 position = glm::vec3(0.f), glm::vec3 origin = glm::vec3(0.f),
		glm::vec3 rotation = glm::vec3(0.f), glm::vec3 scale = glm::vec3(1.f));
	Mesh(const Mesh& obj);
	~Mesh();

	//Modifiers
	void setPosition(float position_x, float position_y, float position_z) override;
	void setOrigin(float _x, float _y, float _z);
	void setRotation(float rotation_x, float rotation_y, float rotation_z) override;
	void setScale(float scale_x, float scale_y, float scale_z) override;

	//Functions
	void move(float position_x, float position_y, float position_z) override;
	void rotate(float rotation_x, float rotation_y, float rotation_z) override;
	void SelfRotate(float _x, float _y, float _z);
	void scaleUp(float scale_x, float scale_y, float scale_z) override;
	void render(Shader* shader);

	//animation
	void Change_text_image(glm::vec2 Left_Up_point, glm::vec2 Left_Down_point,
		glm::vec2 Right_Down_point, glm::vec2 Right_Up_point) override;
};
#endif // !GL_MESH_H_

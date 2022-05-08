#include "OpenGL/Header/GL_Model.h"

Model::Model(glm::vec3 position, glm::vec3 Orgin, Material* material,
	Texture* orTexDif, Texture* orTexSpec,
	Mesh* meshes)
{
	this->position = position;
	this->material = material;
	this->overrideTextureDiffuse = orTexDif;
	this->overrideTextureSpecular = orTexSpec;

	this->meshes = new Mesh(*meshes);

	this->meshes->setPosition(this->position.x, this->position.y, this->position.z);
	this->meshes->setOrigin(Orgin.x, Orgin.y, Orgin.z);
}

//OBJ file loaded model
Model::Model(glm::vec3 position, 
	glm::vec3 rotation, glm::vec3 scale,
	Material* material,
	Texture* orTexDif, Texture* orTexSpec,
	const char* objFile)
{
	this->position = position;
	this->material = material;
	this->overrideTextureDiffuse = orTexDif;
	this->overrideTextureSpecular = orTexSpec;

	std::vector<Vertex> mesh = loadOBJ(objFile);

	this->meshes = (new Mesh(mesh.data(), mesh.size(), NULL, 0, 
		position,
		position,
		rotation,
		scale));

	this->meshes->move(this->position.x, this->position.y, this->position.z);
	this->meshes->setOrigin(this->position.x, this->position.y, this->position.z);

}

Model::~Model()
{
	delete this->meshes;
}

//Functions
void Model::SetOrgin(float _x, float _y, float _z)
{
	this->meshes->setOrigin(_x, _y, _z);
}

void Model::rotate(float rotation_x, float rotation_y, float rotation_z)
{
	this->meshes->rotate(rotation_x, rotation_y, rotation_z);
}

void Model::move(float move_x, float move_y, float move_z)
{
	this->meshes->move(move_x, move_y, move_z);
}

void Model::render(Shader* shader)
{
	//Update uniforms
	this->material->sendToShader(*shader);

	//Use a program (BECAUSE SHADER CLASS LAST UNIFORM UPDATE UNUSES IT)
	shader->use();

	//Activate texture for each mesh
	this->overrideTextureDiffuse->bind(0);
	if (this->overrideTextureSpecular)
	{
		this->overrideTextureSpecular->bind(1);
	}

	this->meshes->render(shader); //Activates shader also
}
#ifndef GL_MODEL_H_
#define GL_MODEL_H_

#include "GL_Mesh.h"
#include "GL_Texture.h"
#include "GL_Shader.h"
#include "GL_Material.h"
#include "GL_OBJLoader.h"
#include "Interface/IModel.h"

class Model : public IModel
{
private:
	Material* material;
	Texture* overrideTextureDiffuse;
	Texture* overrideTextureSpecular;
	glm::vec3 position;
	Mesh* meshes;

public:
	Model(glm::vec3 position, glm::vec3 Orgin, Material* material,
		Texture* orTexDif, Texture* orTexSpec,
		Mesh* meshes);
	//OBJ file loaded model
	Model(glm::vec3 position, glm::vec3 roation, glm::vec3 scale,Material* material,
		Texture* orTexDif, Texture* orTexSpec,
		const char* objFile);
	~Model();

	//Functions
	void SetOrgin(float _x, float _y, float _z) override; 
	void rotate(float rotation_x, float rotation_y, float rotation_z) override;
	void move(float rotation_x, float rotation_y, float rotation_z) override;
	IMesh* Get_Mesh() { return meshes; }
	void render(Shader* shader);
};

#endif // !GL_MODEL_H_
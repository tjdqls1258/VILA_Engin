#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include "Monobehavior.h"
#include "Time.h"
#include "Transform.h"

using namespace std;

class IModel;
class Scene;
class Collision;

enum Mesh_Data
{
	NoMesh = -1,
	Mesh_Triangle,
	Mesh_Quad,
	Mesh_Pyramid,
	Mesh_Cube,
	End
};

class GameObject
{
private:
	list<Monobehavior*> Component;
	list<GameObject*> Child;
	GameObject* Parent;
	Scene* scene;
public:
	const char* Model_Path;
	Mesh_Data mesh_Type;
	IModel* modle;
	IMesh* mesh;
	ITexture* texture = NULL;
	ITexture* texture_specular = NULL;

	Collision* collision;
	Transform* transform;
	string name;

	unsigned int triangleVertexArrayObject;
	unsigned int triangleShaderProgramID;
	unsigned int trianglePositionVertexBufferObjectID, triangleColorVertexBufferObjectID,
		triangleElementBufferObject;

	unsigned int vao;

	GameObject(string name);
	GameObject(string name, const char* Modle_Path);
	~GameObject();

	void SetScene(Scene* scene);
	Scene* GetScene();

	void Set_Collision(Collision* coll);

	void addChild(GameObject* child);
	list<GameObject*> GetChild();
	GameObject* getParent();

	//Set
	void SetModle(IModel* modle);
	void SetTexture(ITexture* text);

	//루프 및 컴포넌트 관련
	void Object_Start();
	void Object_Update();
	void Object_FixedUpdate();
	void Object_Collision_Enter(GameObject* coll);
	void addComponent(Monobehavior* Components);

	//위치 관련
	void setPosition(vec3 vec);
	void setScale(float vec);
	void setScale(vec3 vec);
	void setRotation(vec3 vec);
	void translate(vec3 vec);
	void rotate(vec3 vec);
	void child_rotate(vec3 vec);

	void Render();
};

#endif // !_OBJECT_H_


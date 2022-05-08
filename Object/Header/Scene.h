#ifndef SCENE_H_
#define SCENE_H_

#include <list>
#include <iostream>
#include "GameObject.h"

class IRender;
class ICamera;

class Scene
{
private:
	list<GameObject*> gameobject;
	IRender* Render_Program;
public:
	Scene(IRender* Render);
	IRender* GetRender();
	void addGameObject(GameObject *Object);
	void SetCam(float pos_x, float pos_y, float pos_z, float direction_x,
		float direction_y, float direction_z,
		float WorldUp_x, float WorldUp_y, float WorldUp_z);
	void add_Light(std::string name, vec3 pos, float intensity = 1.f, glm::vec3 color = glm::vec3(1.f),
		float constant = 1.f, float linear = 0.045f, float quadratic = 0.0075f);
	void MoveLight(glm::vec3 pos, std::string name);
	ICamera* GetCam();
	void loop();
};


#endif // !SCENE_H_

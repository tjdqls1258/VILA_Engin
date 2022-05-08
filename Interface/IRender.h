#ifndef IRENDER_H_
#define IRENDER_H_

#include <iostream>
#include <glm/vec3.hpp>

class GameObject;
class ICamera;

class IRender
{
public:
	virtual void render() = 0;
	virtual void init_Obj_Render(GameObject* gaemObject) = 0;
	virtual void AddLight() = 0;
	virtual void SetCamera(float pos_x, float pos_y, float pos_z, float direction_x,
		float direction_y, float direction_z,
		float WorldUp_x, float WorldUp_y, float WorldUp_z) = 0;
	virtual void Instance_Lights(std::string name, glm::vec3 pos, float intensity, glm::vec3 color,
		float constant, float linear, float quadratic) = 0;
	virtual void SetPosition_Lights_Name(std::string Name, glm::vec3 pos) = 0;
	virtual ICamera* GetCamera() = 0;
};

#endif // !IRENDER_H_
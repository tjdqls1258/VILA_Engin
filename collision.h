#ifndef _COLLISION_H_
#define _COLLISION_H_

#include <glm/vec3.hpp>

class GameObject;

class Collision
{
private:
	glm::vec3 postion;
	glm::vec3 scale;
public:
	Collision(glm::vec3 postion, glm::vec3 scale);
	void Set_GameObject(GameObject* gameObject);
	GameObject* gameObject;
	bool OnCollision(Collision* coll);
	//void OnCollisionStay(Collision* coll);
	//void OnCollisionExit(Collision* coll);
};
#endif // _COLLISION_H_
#include "collision.h"
#include "Object/Header/GameObject.h"
Collision::Collision(glm::vec3 postion, glm::vec3 scale) : postion(postion), scale(scale)
{ }

void Collision::Set_GameObject(GameObject* gameObject)
{
	this->gameObject = gameObject;
}

bool Collision::OnCollision(Collision* coll)
{
	glm::vec3 target_pos = coll->gameObject->transform->Position + coll->postion;
	float target_W = coll->scale.x;
	float target_H = coll->scale.y;
	float target_D = coll->scale.z;
	glm::vec3 this_pos = gameObject->transform->Position + postion;

	if (((target_pos.x <= this_pos.x + scale.x) && (target_pos.x >= this_pos.x))
		|| ((target_pos.x + target_W >= this_pos.x) && (target_pos.x + target_W <= this_pos.x + scale.x))) //오른쪽 x가 사이에 있다?
	{
		if (((target_pos.y <= this_pos.y + scale.y) && (target_pos.y >= this_pos.y))
			|| ((target_pos.y + target_H >= this_pos.y) && (target_pos.y + target_H <= this_pos.y + scale.y)))
		{
			if (((target_pos.z <= this_pos.z + scale.z) && (target_pos.z >= this_pos.z))
				|| ((target_pos.z + target_D >= this_pos.z) && (target_pos.z + target_D <= this_pos.z + scale.z)))
			{
				return true;
			}
		}
	}

	return false;
}
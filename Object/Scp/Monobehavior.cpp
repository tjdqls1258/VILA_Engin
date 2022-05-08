#include "Object/Header/Monobehavior.h"
#include "ICamera.h"

Monobehavior::~Monobehavior() {  }

void Monobehavior::SetGameObject(GameObject* gameObject)
{
	this->gameObject = gameObject;
}

void Monobehavior::SetCamObject(ICamera* cam)
{
	this->cam = cam;
}
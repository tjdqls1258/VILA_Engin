#ifndef _MONOBEHAVIOR_H_
#define _MONOBEHAVIOR_H_

#include <list>
#include <iostream>

#include "Input.h"

class GameObject;
class ICamera;
class collision;

class Monobehavior
{
protected:
	GameObject* gameObject;
	ICamera* cam;
public:
	virtual void Start() = 0;
	virtual void FixedUpdate() = 0;
	virtual void Update() = 0;
	virtual ~Monobehavior() = 0;

	virtual void SetGameObject(GameObject* gameObject);
	virtual void SetCamObject(ICamera* cam);

	virtual void IsCoillisionEnter(GameObject* coll) { }
};

#endif // !_MONOBEHAVIOR
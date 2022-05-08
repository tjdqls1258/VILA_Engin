#ifndef ICAMERA_H_
#define ICAMERA_H_

#include <list>
#include "Transform.h"
#include "Object/Header/GameObject.h"
class Monobehavior;
class Transform;

class ICamera
{
protected:
	std::list<Monobehavior*> Component;
	Transform transform;
public:
	virtual void move(float x, float y, float z) = 0;
	virtual void updateMouseInput(const float& dt, const double& offsetX, const double& offsetY) = 0;
	virtual void updateInput(const float& dt, const int direction, const double& offsetX, const double& offsetY) = 0;
	virtual void addComponent(Monobehavior* Components);
	virtual void Object_Start();
	virtual void Object_Update();
	virtual void Object_FixedUpdate();
};

#endif // !ICAMERA_H_
#ifndef _COLLISION_COMPOENT_H_
#define _COLLISION_COMPOENT_H_

#include "Object/Header/Monobehavior.h"

class Collision_Compoent : public Monobehavior
{
	virtual void Start() override;
	virtual void Update() override;
	virtual void FixedUpdate() override;
	virtual void IsCoillisionEnter(GameObject* coll) override;
};


#endif // !_COLLISION_COMPOENT_H_
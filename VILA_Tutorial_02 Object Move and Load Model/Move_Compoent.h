#ifndef _MOVE_COMPOENT_H_
#define _MOVE_COMPOENT_H_

#include "Object/Header/Monobehavior.h"

class Move_Compoent : public Monobehavior
{
	virtual void Start() override;
	virtual void Update() override;
	virtual void FixedUpdate() override;
};

#endif // !_MOVE_COMPOENT_H_
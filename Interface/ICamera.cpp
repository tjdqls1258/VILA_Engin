#include "ICamera.h"
#include "Object/Header/Monobehavior.h"

void ICamera::addComponent(Monobehavior* Components)
{
	Component.emplace_back(Components);
	Components->SetCamObject(this);
}

void ICamera::Object_Start()
{
	for (list<Monobehavior*>::iterator it = Component.begin(); it != Component.end(); it++)
	{
		(*it)->Start();
	}
}

void ICamera::Object_Update()
{
	for (list<Monobehavior*>::iterator it = Component.begin(); it != Component.end(); it++)
	{
		(*it)->Update();
	}
}

void ICamera::Object_FixedUpdate()
{
	for (list<Monobehavior*>::iterator it = Component.begin(); it != Component.end(); it++)
	{
		(*it)->FixedUpdate();
	}
}
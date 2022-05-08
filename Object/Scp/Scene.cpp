#include "Object/Header/Scene.h"
#include "IRender.h"
#include "ICamera.h"

Scene::Scene(IRender* Render)
{
	QueryPerformanceFrequency(&Time::Instance_Time()->Frequency);
	QueryPerformanceCounter(&Time::Instance_Time()->BeginTime);
	QueryPerformanceCounter(&Time::Instance_Time()->EndTime);
	QueryPerformanceCounter(&Time::Instance_Time()->CurrentTime);
	QueryPerformanceCounter(&Time::Instance_Time()->LastTime);

	Time::Instance_Time()->FU_time = 0;
	Time::Instance_Time()->tick = Time::Instance_Time()->Frequency.QuadPart;
	this->Render_Program = Render;
}

IRender* Scene::GetRender()
{
	return this->Render_Program;
}

void Scene::SetCam(float pos_x, float pos_y, float pos_z, float direction_x,
	float direction_y, float direction_z,
	float WorldUp_x, float WorldUp_y, float WorldUp_z)
{
	Render_Program->SetCamera(pos_x, pos_y, pos_z, direction_x, direction_y, direction_z,
		WorldUp_x, WorldUp_y, WorldUp_z);
}

void Scene::MoveLight(glm::vec3 pos, std::string name)
{
	GetRender()->SetPosition_Lights_Name(name,pos);
}

ICamera* Scene::GetCam()
{
	return Render_Program->GetCamera();
}

void Scene::addGameObject(GameObject* Object)
{
	gameobject.emplace_back(Object);
	Object->SetScene(this);
}

void Scene::add_Light(std::string name, vec3 pos, float intensity, glm::vec3 color,
	float constant, float linear, float quadratic)
{
	GetRender()->Instance_Lights(name, pos, intensity, color, constant, linear, quadratic);
}

void Scene::loop()
{
	for (list<GameObject*>::iterator object = gameobject.begin();
		object != gameobject.end(); object++)
	{
		(*object)->Render();
		(*object)->Object_Start();
	}
	if (GetCam())
	{
		GetCam()->Object_Start();
	}
	GetRender()->AddLight();

	while (1)
	{
		QueryPerformanceCounter(&Time::Instance_Time()->CurrentTime);
		//FixedUpdate
		for (list<GameObject*>::iterator object = gameobject.begin();
			object != gameobject.end(); object++)
		{
			Time::Instance_Time()->FU_time =
				(Time::Instance_Time()->EndTime.QuadPart - Time::Instance_Time()->BeginTime.QuadPart) / Time::Instance_Time()->tick;
			if (Time::Instance_Time()->FU_time >= 3) //3 => 3초 간격으로
			{
				if (GetCam())
				{
					GetCam()->Object_FixedUpdate();
				}
				(*object)->Object_FixedUpdate();
			}
		}
		//Update
		if (GetCam())
		{
			GetCam()->Object_Update();
		}

		for (list<GameObject*>::iterator object = gameobject.begin();
			object != gameobject.end(); object++)
		{
			(*object)->Object_Update();
		}

		for (list<GameObject*>::iterator object = gameobject.begin();
			object != gameobject.end(); object++)
		{
			if ((*object)->collision != nullptr)
			{
				for (list<GameObject*>::iterator other_object = gameobject.begin();
					other_object != gameobject.end(); other_object++)
				{
					if (object != other_object)
					{
						(*object)->Object_Collision_Enter(*other_object);
					}
				}
			}
		}
		//Randering
		GetRender()->render();

		Time::Instance_Time()->Reset_Time();
	}
}
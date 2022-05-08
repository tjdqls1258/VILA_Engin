#include "Collision_Compoent.h"
#include "Object/Header/GameObject.h"

void Collision_Compoent::Start()
{
	std::cout << "Collision_Compoent 시작" << std::endl;
}

void Collision_Compoent::Update()
{
	if (Input::input()->GetKeyDown('q'))
	{
		gameObject->translate(vec3(0.01f, 0.0, 0.0));
	}
	if (Input::input()->GetKeyDown('e'))
	{
		gameObject->translate(vec3(-0.01f, 0.0f, 0.0));
	}
}

void Collision_Compoent::FixedUpdate()
{
	std::cout << "Collision_Compoent - FixedUpdate 호출!" << std::endl;
}

//충돌시 이벤트
void Collision_Compoent::IsCoillisionEnter(GameObject* coll)
{
	cout << coll->name << "충돌\n";
	gameObject->rotate(vec3(1.0f, 0.0f, 0.0f));
}
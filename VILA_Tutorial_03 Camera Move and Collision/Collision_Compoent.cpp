#include "Collision_Compoent.h"
#include "Object/Header/GameObject.h"

void Collision_Compoent::Start()
{
	std::cout << "Collision_Compoent ����" << std::endl;
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
	std::cout << "Collision_Compoent - FixedUpdate ȣ��!" << std::endl;
}

//�浹�� �̺�Ʈ
void Collision_Compoent::IsCoillisionEnter(GameObject* coll)
{
	cout << coll->name << "�浹\n";
	gameObject->rotate(vec3(1.0f, 0.0f, 0.0f));
}
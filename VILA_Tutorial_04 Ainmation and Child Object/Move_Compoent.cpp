#include "Move_Compoent.h"
#include "Object/Header/GameObject.h"

void Move_Compoent::Start()
{
}

void Move_Compoent::Update()
{
	//Input -> GetKeyDown(Ű)  �ش� Ű�� �������� �Ǵ�
	if (Input::input()->GetKeyDown('a'))
	{
		gameObject->translate(vec3(0.01f, 0.0, 0.0)); //������Ʈ�� ������ ���� ������Ʈ �̵�
	}
	if (Input::input()->GetKeyDown('d'))
	{
		gameObject->translate(vec3(-0.01f, 0.0, 0.0));
	}
	if (Input::input()->GetKeyDown('w'))
	{
		gameObject->translate(vec3(0.0f, 0.0, 0.01));
	}
	if (Input::input()->GetKeyDown('s'))
	{
		gameObject->translate(vec3(0.0f, 0.0, -0.01));
	}
	if (Input::input()->GetKeyDown('r'))
	{
		gameObject->rotate(vec3(0.0f, 1.0f, 0.0f));
	}
}

void Move_Compoent::FixedUpdate()//3�ʴ� 1ȸ
{

}
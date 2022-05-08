#include "Move_Compoent.h"
#include "Object/Header/GameObject.h"

void Move_Compoent::Start()
{
}

void Move_Compoent::Update()
{
	//Input -> GetKeyDown(키)  해당 키를 눌럿는지 판단
	if (Input::input()->GetKeyDown('a'))
	{
		gameObject->translate(vec3(0.01f, 0.0, 0.0)); //컴포넌트를 소지한 게임 오브젝트 이동
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
}

void Move_Compoent::FixedUpdate()//3초당 1회
{
	gameObject->rotate(vec3(0.0f, 10.0f, 0.0f)); //회전
}
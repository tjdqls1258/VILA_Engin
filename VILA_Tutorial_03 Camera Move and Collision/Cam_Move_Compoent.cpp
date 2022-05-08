#include "Cam_Move_Compoent.h"
#include "Interface/ICamera.h"

void Cam_Move_Compoent::Start()
{
}

void Cam_Move_Compoent::Update()
{
	if (cam) //카메라일 경우
	{
		cam->updateInput(0.01f, 0.01f, Input::input()->GetMouse_Axis_X(), Input::input()->GetMouse_Axis_Y()); // 마우스에 따라 회전
		if (Input::input()->GetKeyDown('w'))
		{
			cam->move(0.01f, 0.0, 0.0); //해당 컴포넌트를 소지한 카메라 이동
		}
		if (Input::input()->GetKeyDown('s'))
		{
			cam->move(-0.01f, 0.0, 0.0);
		}
		if (Input::input()->GetKeyDown('d'))
		{
			cam->move(0.0f, 0.0, 0.01);
		}
		if (Input::input()->GetKeyDown('a'))
		{
			cam->move(0.0f, 0.0, -0.01);
		}
	}
}

void Cam_Move_Compoent::FixedUpdate()//3초당 1회
{
}
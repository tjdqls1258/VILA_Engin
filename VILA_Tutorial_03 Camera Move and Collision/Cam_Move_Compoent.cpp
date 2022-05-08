#include "Cam_Move_Compoent.h"
#include "Interface/ICamera.h"

void Cam_Move_Compoent::Start()
{
}

void Cam_Move_Compoent::Update()
{
	if (cam) //ī�޶��� ���
	{
		cam->updateInput(0.01f, 0.01f, Input::input()->GetMouse_Axis_X(), Input::input()->GetMouse_Axis_Y()); // ���콺�� ���� ȸ��
		if (Input::input()->GetKeyDown('w'))
		{
			cam->move(0.01f, 0.0, 0.0); //�ش� ������Ʈ�� ������ ī�޶� �̵�
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

void Cam_Move_Compoent::FixedUpdate()//3�ʴ� 1ȸ
{
}
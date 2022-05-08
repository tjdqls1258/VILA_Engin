#include "Input.h"
#include <conio.h>

Input* Input::input()
{
	static Input input;
	return &input;
}

char Input::GetKey()
{
	if (_kbhit())
	{
		return _getch();
	}
}

#if defined(OpenGL)
void Input::set_GLFWwindw(GLFWwindow* windows)
{
	this->windows = windows;
}

double Input::GetMouse_Axis_X()
{
	glfwGetCursorPos(this->windows, &this->Mouse_X, &this->Mouse_Y);

	if (this->isfirst)
	{
		this->lastMouseX = this->Mouse_X;
		this->lastMouseY = this->Mouse_Y;
		this->isfirst = false;
	}

	double offsetMouseX = this->Mouse_X - this->lastMouseX;

	this->lastMouseX = this->Mouse_X;

	return offsetMouseX;
}

double Input::GetMouse_Axis_Y()
{
	glfwGetCursorPos(this->windows, &this->Mouse_X, &this->Mouse_Y);
	if (this->isfirst)
	{
		this->lastMouseX = this->Mouse_X;
		this->lastMouseY = this->Mouse_Y;
		this->isfirst = false;
	}
	double offsetMouseY = this->lastMouseY - this->Mouse_Y; // Y좌표는 아래가 양수

	this->lastMouseY = this->Mouse_Y;

	return offsetMouseY; 
}

bool Input::GetKeyDown(char key)
{
	int Key = (int)key;
	if (key >= 'a' && key <= 'z')
		Key = (int)key - 32;
		
	if (glfwGetKey(this->windows, Key) == GLFW_PRESS)
	{
		return true;
	}
	return false;
}

bool Input::Mouse_Click(int butten)
{
	int state = glfwGetMouseButton(this->windows, butten);
	if (state == GLFW_PRESS)
	{
		return true;
	}
	return false;
}

double Input::GetMousePos_X()
{
	glfwGetCursorPos(this->windows, &this->Mouse_X, &this->Mouse_Y);
	return this->Mouse_X;
}

double Input::GetMousePos_Y()
{
	glfwGetCursorPos(this->windows, &this->Mouse_X, &this->Mouse_Y);
	return this->Mouse_Y;
}

#else
bool Input::GetKeyDown(char key)
{
	if (_kbhit())
	{
		if (_getch() == (int)key)
		{
			return true;
		}
	}
	return false;
}

double Input::GetMouse_Axis_X()
{
	return 0.0;
}

double Input::GetMouse_Axis_Y()
{
	return 0.0;
}

double Input::GetMousePos_X()
{
	return 0.0;
}

double Input::GetMousePos_Y()
{
	return 0.0;
}

bool Input::Mouse_Click(int butten)
{
	return false;
}
#endif // OpenGL

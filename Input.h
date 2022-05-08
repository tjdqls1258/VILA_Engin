#ifndef INPUT_H_
#define INPUT_H_

#define OpenGL

#if defined(OpenGL)
#include "OpenGL/Header/OpenGL_H.h"
#endif //OpenGL

enum KeyCode
{
	NoKey = -1,
	ESC_Key = 27,
	LeftArrow = 75,
	RightArrow = 77,
	UpArrow = 72,
	DownArrow = 80,
	End_KeyCode
};
enum Mouse_Click
{
	No_Click = -1,
	Mouse_Left_Click = 0,
	Mouse_Right_Click = 1,
	Mouse_Middle_Click = 2,
	End_MouseClick
};
class Input
{
private:
	double Mouse_X = 0.0;
	double Mouse_Y = 0.0;
	double lastMouseX = 0.0;
	double lastMouseY = 0.0;
	bool isfirst = true;
#if defined(OpenGL)
	GLFWwindow* windows;
#endif // OpenGL

public:
#if defined(OpenGL)
	void set_GLFWwindw(GLFWwindow* windows);
#endif // OpenGL
	double GetMouse_Axis_X();
	double GetMouse_Axis_Y();
	double GetMousePos_X();
	double GetMousePos_Y();

	bool GetKeyDown(char key);
	bool Mouse_Click(int butten);

	char GetKey();
	static Input* input();
};

#endif // !INPUT_H_


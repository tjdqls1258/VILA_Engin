#include "OpenGL/Header/Animator.h"
#include "Object/Header/GameObject.h"

void Animator::Start()
{
	if (this->gameObject->mesh)
	{
		this->GameObject_Mesh = (Mesh*)this->gameObject->mesh;
		Animat_Running();
	}
}

void Animator::Update()
{
	last_time += Time::Instance_Time()->DelaTime();
	if (last_time > Play_time)
	{
		Animat_Running();
		last_time = 0;
	}
}

void Animator::FixedUpdate()
{
}

void Animator::Animat_Running()
{
	float UV_Size_W = (float)sprite_size_w / (float)image_size_w; // ÇÑÄÆ ³ÐÀÌ/ÀüÃ¤ ÀÌ¹ÌÁö ³ÐÀÌ => UV»ó ÇÑÄÆ
	float UV_Size_H = (float)sprite_size_h / (float)image_size_h;
	//std::cout << (UV_Size_W * Now_fram_X) - UV_Size_W << " , " << UV_Size_H - UV_Size_H << "\n";
	this->GameObject_Mesh->Change_text_image(
		  glm::vec2((UV_Size_W * Now_fram_X) - UV_Size_W, (UV_Size_H * Now_fram_Y) - UV_Size_H) //ÁÂÃø »ó´Ü
		, glm::vec2((UV_Size_W * Now_fram_X) - UV_Size_W, (UV_Size_H * Now_fram_Y))				//ÁÂÃø ÇÏ´Ü
		, glm::vec2((UV_Size_W * Now_fram_X)			, (UV_Size_H * Now_fram_Y))				//¿ìÃø ÇÏ´Ü
		, glm::vec2((UV_Size_W * Now_fram_X)			, (UV_Size_H * Now_fram_Y) - UV_Size_H));//¿ìÃø »ó´Ü
	Now_fram_X++;
	if (Now_fram_X > Count_frame)
	{
		Now_fram_X = start_X;
		Now_fram_Y = start_Y;
	}
	if ((UV_Size_W * Now_fram_X) > 1.0f)
	{
		Now_fram_X = 1;
		Now_fram_Y++;
	}
}
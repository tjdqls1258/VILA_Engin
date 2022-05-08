#ifndef _ANIMATOR_H_
#define _ANIMATOR_H_

#include "Object/Header/Monobehavior.h"

class Mesh;

class Animator : public Monobehavior
{
private:
	float Play_time;
	float last_time;
	int Count_frame;
	int start_X, start_Y;
	int Now_fram_X = 1, Now_fram_Y = 1;
	int sprite_size_w, sprite_size_h;
	int image_size_w, image_size_h;
	Mesh* GameObject_Mesh;
public:
	Animator(float time, 
		int sprite_size_w, int sprite_size_h, 
		int image_size_w, int image_size_h, 
		int frame,
		int start_X = 1, int start_Y = 1) : Monobehavior()
	{
		last_time = 0;
		this->Play_time = time;
		this->sprite_size_w = sprite_size_w;
		this->sprite_size_h = sprite_size_h;
		this->image_size_w = image_size_w;
		this->image_size_h = image_size_h;
		this->Count_frame = frame;
		this->start_X = start_X;
		this->start_Y = start_Y;
		Now_fram_X = start_X;
		Now_fram_Y = start_Y;
	}

	void Start() override;
	void Update() override;
	void FixedUpdate() override;

	void Animat_Running();
};

#endif // !ANIMATOR_H_
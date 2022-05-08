#include "Transform.h"

void Transform::SetPostion(vec3 vec)
{
	Position = vec;
	Orgin = Position;
}

void Transform::SetScale(vec3 vec)
{
	Scale = vec;
}

void Transform::SetRotation(vec3 vec)
{
	Rotation = vec;
}

void Transform::AddPostion(vec3 vec)
{
	Position = Position + vec;
	Orgin = Orgin + vec;
}

void Transform::AddScale(vec3 vec)
{
	Scale = Scale + vec;
}

void Transform::AddRotation(vec3 vec)
{
	Rotation = Rotation + vec;
}
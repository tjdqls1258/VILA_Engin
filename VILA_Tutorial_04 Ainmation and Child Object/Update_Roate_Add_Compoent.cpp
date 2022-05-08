#include "Update_Roate_Add_Compoent.h"
#include "Object/Header/GameObject.h"

void Update_Roate_Add_Compoent::Start()
{

}

void Update_Roate_Add_Compoent::Update()
{
	gameObject->rotate(vec3(1.0f, 0.0f, 0.0f));
}

void Update_Roate_Add_Compoent::FixedUpdate()
{

}
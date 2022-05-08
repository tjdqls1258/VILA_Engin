#include "Interface/IRender.h"		//������ �������̽�
#include "Create_OpenGL.h"			//opengl ������ ���
#include "Object/Header/Scene.h"	//�� ���
#include "OpenGL/Header/Animator.h"	//�ִϸ��̼� ���
#include "Move_Compoent.h"
#include "Update_Roate_Add_Compoent.h"


void main()
{
	//Reander
	Create_OpenGL OpenGL_Div("TUTORIAL", 1920, 1080, glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
	IRender* OpenGL_ = OpenGL_Div.create();

	//Secen ����
	Scene* Scene01 = new Scene(OpenGL_);
	Scene01->SetCam(0, 0, 1, 0, 0, 1, 0, 1, 0); //�ش� ���� ī�޶� ���� ( ��ġ , �ٶ󺸴� ����,  ��)

	//Texture ���� (��������Ʈ �̹���)
	ITexture* texture = (ITexture*)(new Texture("2D_sprite_horse.png"));
	
	//GameObject ����
	GameObject* Obj1 = new GameObject("obj1");
	GameObject* Obj2 = new GameObject("obj2");

	//��ġ ����
	Obj1->setPosition(vec3(1.5f, 0.0f, -1.0f));
	Obj2->setPosition(vec3(-1.0f, 0.0f, -1.0f));

	//������Ʈ �߰�
	Obj1->addComponent(new Move_Compoent());
	Obj2->addComponent(new Update_Roate_Add_Compoent());

	//Object�� texture bind
	Obj1->SetTexture(texture);

	//�ִϸ��̼� ����
	Obj1->addComponent(new Animator(0.2f, 1, 1, 4, 3, 4));

	Obj1->mesh_Type = Mesh_Quad;

	//�ڽİ�ü
	Obj1->addChild(Obj2);

	Scene01->addGameObject(Obj1);

	//loop
	Scene01->loop();

	delete Scene01;
	delete Obj1;
	delete Obj2;
}
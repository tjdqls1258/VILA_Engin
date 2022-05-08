#include "Interface/IRender.h"		//������ �������̽�
#include "Create_OpenGL.h"			//opengl ������ ���
#include "Object/Header/Scene.h"	//�� ���
#include "collision.h"				//�ݶ��̴� ���
#include "Cam_Move_Compoent.h"		//ī�޶� �̵� ������Ʈ
#include "Collision_Compoent.h"		//�浹 ó�� ������Ʈ

int main()
{
	//Reander ����
	Create_OpenGL OpenGL_Div("TUTORIAL", 1920, 1080, glm::vec4(1.0f, 1.0f, 1.0f, 1.0f)); //������ �̸� , ���� ���� , ������ ����
	IRender* OpenGL_ = OpenGL_Div.create();

	//Secen ����
	Scene* Scene01 = new Scene(OpenGL_);
	Scene01->SetCam(0, 0, 1, 0, 0, 1, 0, 1, 0); //�ش� ���� ī�޶� ���� ( ��ġ , �ٶ󺸴� ����,  ��)
	Scene01->GetCam()->addComponent(new Cam_Move_Compoent());//�ش� ���� �ִ� ī�޶� ������Ʈ ����

	//�⺻ �޽��� ������ GameObject ����
	GameObject* Obj1 = new GameObject("obj1"); //obj1�̶�� �̸��� ���� ������Ʈ ����
	GameObject* Obj2 = new GameObject("obj2");

	Obj1->Set_Collision(new Collision(
		vec3(0.0f, 0.0f, 0.0f),
		vec3(1.0f, 1.0f, 1.0f))); //GameObject ���� ��ġ ũ��
	Obj2->Set_Collision(new Collision(
		vec3(0.0f, 0.0f, 0.0f),
		vec3(1.0f, 1.0f, 1.0f))); //GameObject ���� ��ġ ũ��

	//GameObject�� Compoent���̱� 
	Obj1->addComponent(new Collision_Compoent());


	//��ġ ����
	Obj1->setPosition(vec3(1.5f, 0.0f, -1.0f));
	Obj2->setPosition(vec3(-1.0f, 0.0f, -1.0f));

	//�⺻ ���� �޽�
	Obj1->mesh_Type = Mesh_Cube; //�⺻ ���� �޽� ������ (Mesh_Triangle, Mesh_Quad, Mesh_Pyramid, Mesh_Cube)
	Obj2->mesh_Type = Mesh_Cube;

	//Secen�� GameObject �߰�
	Scene01->addGameObject(Obj1);
	Scene01->addGameObject(Obj2);

	//loop
	Scene01->loop();

	//delete
	delete Scene01;
	delete Obj1;
	delete Obj2;
}
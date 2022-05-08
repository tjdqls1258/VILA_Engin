#include "Interface/IRender.h"		//������ �������̽�
#include "Create_OpenGL.h"			//opengl ������ ���
#include "Object/Header/Scene.h"	//�� ���

int main()
{
	//Reander ����
	Create_OpenGL OpenGL_Div("TUTORIAL", 1920, 1080, glm::vec4(1.0f,1.0f,1.0f,1.0f)); //������ �̸� , ���� ���� ,
	IRender* OpenGL_ = OpenGL_Div.create();

	//Secen ����
	Scene* Scene01 = new Scene(OpenGL_);
	Scene01->SetCam(0, 0, 1, 0, 0, 1, 0, 1, 0); //�ش� ���� ī�޶� ���� ( ��ġ , �ٶ󺸴� ����,  ��)

	//GameObject ����
	GameObject* Obj1 = new GameObject("obj1"); //obj1�̶�� �̸��� ���� ������Ʈ ����
	GameObject* Obj2 = new GameObject("obj2");

	//��ġ ����
	Obj1->setPosition(vec3(0.0f, 0.0f, -1.0f)); //��ġ
	Obj1->setRotation(vec3(0.0f, 20.0f, 0.0f));	//ȸ��
	Obj1->setScale(vec3(1.0f, 1.0f, 1.0f));//������

	Obj2->setPosition(vec3(2.0f, 0.0f, -1.0f)); //��ġ
	Obj2->setRotation(vec3(0.0f, 20.0f, 0.0f));	//ȸ��
	Obj2->setScale(vec3(1.0f, 1.0f, 1.0f));//������

	//�⺻ ���� �޽�
	Obj1->mesh_Type = Mesh_Cube; //�⺻ ���� �޽� ������ (Mesh_Triangle, Mesh_Quad, Mesh_Pyramid, Mesh_Cube)
	Obj2->mesh_Type = Mesh_Pyramid;

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
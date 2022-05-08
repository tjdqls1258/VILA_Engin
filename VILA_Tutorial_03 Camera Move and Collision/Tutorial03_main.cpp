#include "Interface/IRender.h"		//랜더러 인터페이스
#include "Create_OpenGL.h"			//opengl 랜더러 헤더
#include "Object/Header/Scene.h"	//씬 헤더
#include "collision.h"				//콜라이더 사용
#include "Cam_Move_Compoent.h"		//카메라 이동 컴포넌트
#include "Collision_Compoent.h"		//충돌 처리 컴포넌트

int main()
{
	//Reander 생성
	Create_OpenGL OpenGL_Div("TUTORIAL", 1920, 1080, glm::vec4(1.0f, 1.0f, 1.0f, 1.0f)); //윈도우 이름 , 넓이 높이 , 윈도우 색상
	IRender* OpenGL_ = OpenGL_Div.create();

	//Secen 생성
	Scene* Scene01 = new Scene(OpenGL_);
	Scene01->SetCam(0, 0, 1, 0, 0, 1, 0, 1, 0); //해당 씬의 카메라 설정 ( 위치 , 바라보는 방향,  축)
	Scene01->GetCam()->addComponent(new Cam_Move_Compoent());//해당 씬에 있는 카메라에 컴포넌트 붙임

	//기본 메쉬를 가지는 GameObject 생성
	GameObject* Obj1 = new GameObject("obj1"); //obj1이라는 이름을 가진 오브젝트 생성
	GameObject* Obj2 = new GameObject("obj2");

	Obj1->Set_Collision(new Collision(
		vec3(0.0f, 0.0f, 0.0f),
		vec3(1.0f, 1.0f, 1.0f))); //GameObject 기준 위치 크기
	Obj2->Set_Collision(new Collision(
		vec3(0.0f, 0.0f, 0.0f),
		vec3(1.0f, 1.0f, 1.0f))); //GameObject 기준 위치 크기

	//GameObject에 Compoent붙이기 
	Obj1->addComponent(new Collision_Compoent());


	//위치 관련
	Obj1->setPosition(vec3(1.5f, 0.0f, -1.0f));
	Obj2->setPosition(vec3(-1.0f, 0.0f, -1.0f));

	//기본 제공 메쉬
	Obj1->mesh_Type = Mesh_Cube; //기본 제공 메쉬 데이터 (Mesh_Triangle, Mesh_Quad, Mesh_Pyramid, Mesh_Cube)
	Obj2->mesh_Type = Mesh_Cube;

	//Secen에 GameObject 추가
	Scene01->addGameObject(Obj1);
	Scene01->addGameObject(Obj2);

	//loop
	Scene01->loop();

	//delete
	delete Scene01;
	delete Obj1;
	delete Obj2;
}
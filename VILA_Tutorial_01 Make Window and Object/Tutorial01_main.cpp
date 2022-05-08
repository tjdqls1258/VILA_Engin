#include "Interface/IRender.h"		//랜더러 인터페이스
#include "Create_OpenGL.h"			//opengl 랜더러 헤더
#include "Object/Header/Scene.h"	//씬 헤더

int main()
{
	//Reander 생성
	Create_OpenGL OpenGL_Div("TUTORIAL", 1920, 1080, glm::vec4(1.0f,1.0f,1.0f,1.0f)); //윈도우 이름 , 넓이 높이 ,
	IRender* OpenGL_ = OpenGL_Div.create();

	//Secen 생성
	Scene* Scene01 = new Scene(OpenGL_);
	Scene01->SetCam(0, 0, 1, 0, 0, 1, 0, 1, 0); //해당 씬의 카메라 설정 ( 위치 , 바라보는 방향,  축)

	//GameObject 생성
	GameObject* Obj1 = new GameObject("obj1"); //obj1이라는 이름을 가진 오브젝트 생성
	GameObject* Obj2 = new GameObject("obj2");

	//위치 관련
	Obj1->setPosition(vec3(0.0f, 0.0f, -1.0f)); //위치
	Obj1->setRotation(vec3(0.0f, 20.0f, 0.0f));	//회전
	Obj1->setScale(vec3(1.0f, 1.0f, 1.0f));//사이즈

	Obj2->setPosition(vec3(2.0f, 0.0f, -1.0f)); //위치
	Obj2->setRotation(vec3(0.0f, 20.0f, 0.0f));	//회전
	Obj2->setScale(vec3(1.0f, 1.0f, 1.0f));//사이즈

	//기본 제공 메쉬
	Obj1->mesh_Type = Mesh_Cube; //기본 제공 메쉬 데이터 (Mesh_Triangle, Mesh_Quad, Mesh_Pyramid, Mesh_Cube)
	Obj2->mesh_Type = Mesh_Pyramid;

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
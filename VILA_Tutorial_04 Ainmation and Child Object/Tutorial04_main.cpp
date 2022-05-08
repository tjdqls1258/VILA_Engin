#include "Interface/IRender.h"		//랜더러 인터페이스
#include "Create_OpenGL.h"			//opengl 랜더러 헤더
#include "Object/Header/Scene.h"	//씬 헤더
#include "OpenGL/Header/Animator.h"	//애니메이션 헤더
#include "Move_Compoent.h"
#include "Update_Roate_Add_Compoent.h"


void main()
{
	//Reander
	Create_OpenGL OpenGL_Div("TUTORIAL", 1920, 1080, glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
	IRender* OpenGL_ = OpenGL_Div.create();

	//Secen 생성
	Scene* Scene01 = new Scene(OpenGL_);
	Scene01->SetCam(0, 0, 1, 0, 0, 1, 0, 1, 0); //해당 씬의 카메라 설정 ( 위치 , 바라보는 방향,  축)

	//Texture 생성 (스프라이트 이미지)
	ITexture* texture = (ITexture*)(new Texture("2D_sprite_horse.png"));
	
	//GameObject 생성
	GameObject* Obj1 = new GameObject("obj1");
	GameObject* Obj2 = new GameObject("obj2");

	//위치 관련
	Obj1->setPosition(vec3(1.5f, 0.0f, -1.0f));
	Obj2->setPosition(vec3(-1.0f, 0.0f, -1.0f));

	//컴포넌트 추가
	Obj1->addComponent(new Move_Compoent());
	Obj2->addComponent(new Update_Roate_Add_Compoent());

	//Object에 texture bind
	Obj1->SetTexture(texture);

	//애니메이션 적용
	Obj1->addComponent(new Animator(0.2f, 1, 1, 4, 3, 4));

	Obj1->mesh_Type = Mesh_Quad;

	//자식객체
	Obj1->addChild(Obj2);

	Scene01->addGameObject(Obj1);

	//loop
	Scene01->loop();

	delete Scene01;
	delete Obj1;
	delete Obj2;
}
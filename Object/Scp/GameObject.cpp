#include "Object/Header/GameObject.h"
#include "Object/Header/Scene.h"
#include "IRender.h"
#include "IModel.h"
#include "collision.h"

GameObject::GameObject(string name)
{ //초기화
	Parent = nullptr;
	collision = nullptr;
	transform = new Transform;
	this->name = name;
	this->Model_Path = NULL;
	//const char*
}

GameObject::GameObject(string name, const char* Model_Path)
{ //초기화
	Parent = nullptr;
	collision = nullptr;
	transform = new Transform;
	this->name = name;
	this->Model_Path = Model_Path;
}

GameObject::~GameObject()
{
	if (Parent != nullptr)
	{
		for (list<GameObject*>::iterator it = Parent->Child.begin(); it != Parent->Child.end(); it++)
		{
			if ((*it) == this)
			{
				Parent->Child.erase(it);
			}
		}
	}
	this->Child.clear();
	this->Component.clear();
	delete transform;
	delete modle;
	delete mesh;
}

void GameObject::SetScene(Scene* scene)
{
	this->scene = scene;
	for (list<GameObject*>::iterator it = Child.begin(); it != Child.end(); it++)
	{
		(*it)->SetScene(scene);
	}
}

Scene* GameObject::GetScene()
{
	return scene;
}

void GameObject::Set_Collision(Collision* coll)
{
	this->collision = coll;
	coll->Set_GameObject(this);
}

void GameObject::addChild(GameObject* child)
{
	Child.emplace_back(child);
	child->Parent = this;
	child->transform->Orgin = this->transform->Orgin;
}

list<GameObject*> GameObject::GetChild()
{
	return Child;
}

GameObject* GameObject::getParent()
{
	return Parent;
}

void GameObject::SetModle(IModel* modle)
{
	this->modle = modle;
	this->mesh = this->modle->Get_Mesh();
}

void GameObject::SetTexture(ITexture* text)
{
	this->texture = text;
}

void GameObject::Object_Start()
{
	for (list<Monobehavior*>::iterator it = Component.begin(); it != Component.end(); it++)
	{
		(*it)->Start();
	}
	for (list<GameObject*>::iterator it = Child.begin(); it != Child.end(); it++)
	{
		(*it)->Object_Start();
	}
}

void GameObject::Object_Update()
{
	for (list<Monobehavior*>::iterator it = Component.begin(); it != Component.end(); it++)
	{
		(*it)->Update();
	}
	for (list<GameObject*>::iterator it = Child.begin(); it != Child.end(); it++)
	{
		(*it)->Object_Update();
	}
}

void GameObject::Object_FixedUpdate()
{
	for (list<Monobehavior*>::iterator it = Component.begin(); it != Component.end(); it++)
	{
		(*it)->FixedUpdate();
	}
	for (list<GameObject*>::iterator it = Child.begin(); it != Child.end(); it++)
	{
		(*it)->Object_FixedUpdate();
	}
}

void GameObject::Object_Collision_Enter(GameObject* coll)
{
	if ((collision != nullptr) && (coll->collision != nullptr))
	{
		if (this->collision->OnCollision(coll->collision))
		{
			for (list<Monobehavior*>::iterator it = Component.begin(); it != Component.end(); it++)
			{
				(*it)->IsCoillisionEnter(coll);
			}
		}
	}
}

void GameObject::addComponent(Monobehavior* Components)
{
	Component.emplace_back(Components);
	Components->SetGameObject(this);
}

void GameObject::setPosition(vec3 vec)
{
	if (!Parent)
	{
		this->transform->Position = vec;
		this->transform->Orgin = vec;
		if (mesh)
		{
			mesh->setPosition(vec.x,vec.y,vec.z);
		}
	}
	else
	{
		this->transform->Position = Parent->transform->Position + vec;
		if (mesh)
		{
			mesh->setPosition(this->transform->Position.x, this->transform->Position.y, this->transform->Position.z);
		}
	}
	for (list<GameObject*>::iterator it = Child.begin(); it != Child.end(); it++)
	{
		if ((*it)->modle)
		{
			(*it)->modle->SetOrgin(this->transform->Orgin.x, this->transform->Orgin.y, this->transform->Orgin.z);
			(*it)->modle->move(0,0,0);
		}
	}
}

void GameObject::setScale(vec3 vec)
{
	this->transform->SetScale(vec);
	if (mesh)
	{
		this->mesh->setScale(vec.x, vec.y, vec.z);
	}
}

void GameObject::setScale(float scale)
{
	this->transform->SetScale(vec3(scale, scale, scale));
	if (mesh)
	{
		this->mesh->setScale(scale, scale, scale);
	}
}

void GameObject::setRotation(vec3 vec)
{
	this->transform->SetRotation(vec);
	if (mesh)
	{
		this->mesh->SelfRotate(vec.x, vec.y, vec.z);
	}
}

void GameObject::translate(vec3 vec)
{
	this->transform->AddPostion(vec);
	this->modle->move(vec.x,vec.y,vec.z);
	if (!Parent)
	{
		this->modle->SetOrgin(
			this->transform->Position.x, this->transform->Position.y, this->transform->Position.z);
		this->transform->Orgin = this->transform->Position;
	}
	else if (Parent)
	{
		this->modle->SetOrgin(
			Parent->transform->Orgin.x, Parent->transform->Orgin.y, Parent->transform->Orgin.z);
		this->transform->Orgin = Parent->transform->Orgin;
	}
	for (list<GameObject*>::iterator it = Child.begin(); it != Child.end(); it++)
	{
		(*it)->translate(vec);
	}
}

void GameObject::rotate(vec3 vec)
{
	this->transform->AddRotation(vec);
	this->mesh->SelfRotate(vec.x, vec.y, vec.z); //자기 자신을 회전하는 부분
	
	for (list<GameObject*>::iterator it = Child.begin(); it != Child.end(); it++)
	{
		(*it)->child_rotate(vec);
	}
}

void GameObject::child_rotate(vec3 vec)
{
	this->transform->AddRotation(vec);
	this->modle->rotate(vec.x, vec.y, vec.z);

	for (list<GameObject*>::iterator it = Child.begin(); it != Child.end(); it++)
	{
		(*it)->child_rotate(vec);
	}
}

void GameObject::Render()
{
	//그리기
	for (list<GameObject*>::iterator it = Child.begin(); it != Child.end(); it++)
	{
		(*it)->Render();
	}
	GetScene()->GetRender()->init_Obj_Render(this);
}
#include "OpenGL/Header/Reander_OpenGL.h"
#include "Object/Header/GameObject.h"
#include "Interface/IModel.h"
//Private functions
void Reander_OpenGL::initGLFW()
{
	//INIT GLFW
	if (glfwInit() == GLFW_FALSE)
	{
		std::cout << "ERROR::GLFW_INIT_FAILED" << "\n";
		glfwTerminate();
	}
}

void Reander_OpenGL::initWindow(const char* title,
	bool resizable)
{
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, this->GL_VERSION_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, this->GL_VERSION_MINOR);
	glfwWindowHint(GLFW_RESIZABLE, resizable);

	this->window = glfwCreateWindow(
		this->WINDOW_WIDTH, 
		this->WINDOW_HEIGHT, 
		title, 
		NULL, 
		NULL);

	if (this->window == nullptr)
	{
		std::cout << "ERROR::GLFW_WINDOW_INIT_FAILED" << "\n";
		glfwTerminate();
	}

	glfwGetFramebufferSize(
		this->window,
		&this->framebufferWidth,
		&this->framebufferHeight
	);
	glfwSetFramebufferSizeCallback(
		window,
		Reander_OpenGL::framebuffer_resize_callback);

	glfwMakeContextCurrent(this->window); //IMPORTANT!!

	Input::input()->set_GLFWwindw(this->window);
}

void Reander_OpenGL::initGLEW()
{
	//INIT GLEW (NEEDS WINDOW AND OPENGL CONTEXT)
	glewExperimental = GL_TRUE;
	
	//Error
	if (glewInit() != GLEW_OK)
	{
		std::cout << "ERROR::MAIN.CPP::GLEW_INIT_FAILED" << "\n";
		glfwTerminate();
	}
}

void Reander_OpenGL::initOpenGLOptions()
{
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void Reander_OpenGL::initMatrices()
{
	this->ViewMatrix = glm::mat4(1.f);
	this->ViewMatrix = glm::lookAt(
		this->camPosition, 
		this->camPosition + this->camFront, 
		this->worldUp);

	this->ProjectionMatrix = glm::mat4(1.f);
	this->ProjectionMatrix = glm::perspective(
		glm::radians(this->fov),
		static_cast<float>(this->framebufferWidth) / this->framebufferHeight,
		this->nearPlane,
		this->farPlane);
}

void Reander_OpenGL::initShaders()
{
	this->shaders.push_back(new Shader(
		this->GL_VERSION_MAJOR, 
		this->GL_VERSION_MINOR,
		"..\\GLSL\\vertex_core.glsl", 
		"..\\GLSL\\fragment_core.glsl"));
}

void Reander_OpenGL::initTextures()
{
	//TEXTURE 0
	this->textures.push_back(new Texture("..\\VILA_Engin\\Images\\container.png"));
	this->textures.push_back(new Texture("..\\VILA_Engin\\Images\\container_specular.png"));
}

void Reander_OpenGL::initMaterials()
{
	this->materials.push_back(
		new Material(
			glm::vec3(0.1f), 
			glm::vec3(1.f), 
			glm::vec3(1.f),
			0,
			1
		));
}

void Reander_OpenGL::initModels(GameObject* gameObject)
{ 
	Mesh* meshes = new Mesh(
		new Quad(),
		gameObject->transform->Position,
		gameObject->transform->Orgin,
		gameObject->transform->Rotation,
		gameObject->transform->Scale);

	switch (gameObject->mesh_Type)
	{
	case Mesh_Triangle:
		meshes = new Mesh(
			new Triangle(),
			gameObject->transform->Position,
			gameObject->transform->Orgin,
			gameObject->transform->Rotation,
			gameObject->transform->Scale);
		break;
	case Mesh_Quad:
		meshes = new Mesh(
			new Quad(),
			gameObject->transform->Position,
			gameObject->transform->Orgin,
			gameObject->transform->Rotation,
			gameObject->transform->Scale);
		break;
	case Mesh_Pyramid:
		meshes = new Mesh(
			new Pyramid(),
			gameObject->transform->Position,
			gameObject->transform->Orgin,
			gameObject->transform->Rotation, 
			gameObject->transform->Scale);
		break;
	case Mesh_Cube:
		meshes = new Mesh(
			new Cube(),
			gameObject->transform->Position,
			gameObject->transform->Orgin,
			gameObject->transform->Rotation, 
			gameObject->transform->Scale);
		break;
	default:
		break;
	}
	if (gameObject->texture == NULL)
	{
		gameObject->texture = this->textures[TEX_CONTAINER];
		gameObject->texture_specular = this->textures[TEX_CONTAINER_SPECULAR];
	}
	if (gameObject->Model_Path != NULL)
	{
		gameObject->SetModle(new Model(
			gameObject->transform->Position,
			gameObject->transform->Rotation,
			gameObject->transform->Scale,
			this->materials[0],
			(Texture*)gameObject->texture,
			(Texture*)gameObject->texture_specular,
			gameObject->Model_Path));
	}
	else
	{
		gameObject->SetModle(new Model((
			gameObject->transform->Position),
			gameObject->transform->Orgin
			, this->materials[0],
			(Texture*)gameObject->texture, 
			(Texture*)gameObject->texture_specular,
			meshes));
	}
	this->models.push_back((Model*)(gameObject->modle));

	delete meshes;
}

void Reander_OpenGL::initPointLights()
{
	this->pointLights.push_back(new PointLight("Defual",glm::vec3(0.f)));
}

void Reander_OpenGL::initLights()
{
	this->initPointLights();
}

void Reander_OpenGL::Instance_Lights(std::string name, vec3 pos, float intensity = 1.f, glm::vec3 color = glm::vec3(1.f),
	float constant = 1.f, float linear = 0.045f, float quadratic = 0.0075f)
{
	this->pointLights.push_back(new PointLight(name, pos, intensity, color, constant, linear, quadratic));
	initUniforms();
}

void Reander_OpenGL::SetPosition_Lights_Name(std::string Name, vec3 pos)
{
	updateUniforms();
	for (std::vector<PointLight*>::iterator pl = this->pointLights.begin();
		pl < this->pointLights.end();
		pl++)
	{
		if ((*pl)->Name == Name)
		{
			(*pl)->setPosition(pos);
		}
	}
}

void Reander_OpenGL::initUniforms()
{
	this->shaders[SHADER_CORE_PROGRAM]->setMat4fv(ViewMatrix, "ViewMatrix");
	this->shaders[SHADER_CORE_PROGRAM]->setMat4fv(ProjectionMatrix, "ProjectionMatrix");

	for(PointLight * pl : this->pointLights)
	{
		pl->sendToShader(*this->shaders[SHADER_CORE_PROGRAM]);
	}
}

void Reander_OpenGL::updateUniforms()
{
	//Update view matrix (camera)
	this->ViewMatrix = this->camera->getViewMatrix();

	this->shaders[SHADER_CORE_PROGRAM]->setMat4fv(this->ViewMatrix, "ViewMatrix");
	this->shaders[SHADER_CORE_PROGRAM]->setVec3f(this->camera->getPosition(), "cameraPos");

	for(PointLight * pl : this->pointLights)
	{
		pl->sendToShader(*this->shaders[SHADER_CORE_PROGRAM]);
	}

	//Update framebuffer size and projection matrix
	glfwGetFramebufferSize(this->window, &this->framebufferWidth, &this->framebufferHeight);

	this->ProjectionMatrix = glm::perspective(
		glm::radians(this->fov),
		static_cast<float>(this->framebufferWidth) / this->framebufferHeight,
		this->nearPlane,
		this->farPlane
	);

	this->shaders[SHADER_CORE_PROGRAM]->setMat4fv(this->ProjectionMatrix, "ProjectionMatrix");
}

Reander_OpenGL::Reander_OpenGL(const char* title, const int WINDOW_WIDTH, const int WINDOW_HEIGHT,
	const int GL_VERSION_MAJOR, const int GL_VERSION_MINOR, bool resizable, glm::vec4 color) : 
	WINDOW_WIDTH(WINDOW_WIDTH), WINDOW_HEIGHT(WINDOW_HEIGHT),
GL_VERSION_MAJOR(GL_VERSION_MAJOR), GL_VERSION_MINOR(GL_VERSION_MINOR), Windows_color(color)
{
	//Init variables
	this->window = nullptr;
	this->framebufferWidth = this->WINDOW_WIDTH;
	this->framebufferHeight = this->WINDOW_HEIGHT;

	this->camPosition = glm::vec3(0.f, 0.f, -1.f);
	this->worldUp = glm::vec3(0.f, 1.f, 0.f);
	this->camFront = glm::vec3(0.f, 0.f, -1.f);

	this->fov = 90.f;
	this->nearPlane = 0.1f;
	this->farPlane = 1000.f;

	this->initGLFW();
	this->initWindow(title, resizable);
	this->initGLEW();
	this->initOpenGLOptions();

	this->initMatrices();
	this->initShaders();
	this->initTextures();
	this->initMaterials();
}

Reander_OpenGL::~Reander_OpenGL()
{
	glfwDestroyWindow(this->window);
	glfwTerminate();

	for (size_t i = 0; i < this->shaders.size(); i++)
		delete this->shaders[i];

	for (size_t i = 0; i < this->textures.size(); i++)
		delete this->textures[i];

	for (size_t i = 0; i < this->materials.size(); i++)
		delete this->materials[i];

	for (auto*& i : this->models)
		delete i;

	for (size_t i = 0; i < this->pointLights.size(); i++)
		delete this->pointLights[i];
}

//Accessor
int Reander_OpenGL::getWindowShouldClose()
{
	return glfwWindowShouldClose(this->window);
}

//Modifier
void Reander_OpenGL::setWindowShouldClose()
{
	glfwSetWindowShouldClose(this->window, GLFW_TRUE);
}

void Reander_OpenGL::render()
{
	glfwPollEvents();//키보드, 마우스 입력 이벤트 사용
	//Clear
	glClearColor(Windows_color.x, Windows_color.y, Windows_color.z, Windows_color.a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	//Update the uniforms
	this->updateUniforms();

	//모델들그려줌
	for (auto& i : this->models)
	{
		i->render(this->shaders[SHADER_CORE_PROGRAM]);
	}

	//End Draw
	glfwSwapBuffers(window);
	glFlush();

	glBindVertexArray(0);
	glUseProgram(0);
	glActiveTexture(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Reander_OpenGL::init_Obj_Render(GameObject* gameObject)
{
	this->initModels(gameObject);
}

void Reander_OpenGL::AddLight()
{
	this->initLights();
	this->initUniforms();
}

//Static functions
void Reander_OpenGL::framebuffer_resize_callback(GLFWwindow* window, int fbW, int fbH)
{
	glViewport(0, 0, fbW, fbH);
};

void Reander_OpenGL::SetCamera(float pos_x, float pos_y, float pos_z, float direction_x,
	float direction_y, float direction_z,
	float WorldUp_x, float WorldUp_y, float WorldUp_z)
{
	this->camera = new Camera(
		pos_x, pos_y, pos_z, 
		direction_x,
		direction_y, direction_z,
		WorldUp_x, WorldUp_y, WorldUp_z);
}

ICamera* Reander_OpenGL::GetCamera()
{
	return this->camera;
}
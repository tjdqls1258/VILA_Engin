#ifndef REANDER_OPENGL_H_
#define REANDER_OPENGL_H_

#include "Interface/IRender.h"
#include "OpenGL_H.h"
#include "GL_Camera.h"

enum shader_enum { SHADER_CORE_PROGRAM = 0 };
enum texture_enum { TEX_Defulat = -1,TEX_CONTAINER, TEX_CONTAINER_SPECULAR };
enum material_enum { MAT_1 = 0 };
enum mesh_enum { MESH_QUAD = 0 };

class Reander_OpenGL : public IRender
{
private:
	//Window
	GLFWwindow* window;
	const int WINDOW_WIDTH;
	const int WINDOW_HEIGHT;
	int framebufferWidth;
	int framebufferHeight;
	glm::vec4 Windows_color;
	//OpenGL Context
	const int GL_VERSION_MAJOR;
	const int GL_VERSION_MINOR;
	//Camera
	Camera* camera;
	//Matrices
	glm::mat4 ViewMatrix;
	glm::vec3 camPosition;
	glm::vec3 worldUp;
	glm::vec3 camFront;
	glm::mat4 ProjectionMatrix;
	float fov;
	float nearPlane;
	float farPlane;
	//Shaders
	std::vector<Shader*> shaders;
	//Textures
	std::vector<Texture*> textures;
	//Materials
	std::vector<Material*> materials;
	//Models
	std::vector<Model*> models;
	//Mesh
	//std::vector<Mesh*> meshes;
	//Lights
	std::vector<PointLight*> pointLights;

	//Private functions
	void initGLFW();
	void initWindow(const char* title, bool resizable);
	void initGLEW();
	void initOpenGLOptions();
	void initMatrices();
	void initShaders();
	void initTextures();
	void initMaterials();
	void initModels(GameObject* gameObject);
	void initPointLights();
	void initLights();
	void initUniforms();
	void updateUniforms();
public:
	//Constructors / Destructors
	Reander_OpenGL(const char* title, const int WINDOW_WIDTH, const int WINDOW_HEIGHT,
		const int GL_VERSION_MAJOR, const int GL_VERSION_MINOR, bool resizable, glm::vec4 color);
	virtual ~Reander_OpenGL();
	//Accessors
	int getWindowShouldClose();
	//Modifiers
	void setWindowShouldClose();
	//Functions
	void render() override;
	void init_Obj_Render(GameObject* gaemObject) override;
	void AddLight() override;
	virtual void Instance_Lights(std::string name, vec3 pos, float intensity, glm::vec3 color,
		float constant, float linear, float quadratic) override;
	void SetPosition_Lights_Name(std::string Name, vec3 pos) override;
	
	void SetCamera(float pos_x, float pos_y, float pos_z, float direction_x,
		float direction_y, float direction_z,
		float WorldUp_x, float WorldUp_y, float WorldUp_z) override;
	ICamera* GetCamera() override;
	//Static functions
	static void framebuffer_resize_callback(GLFWwindow* window, int fbW, int fbH);
};

#endif // !REANDER_OPENGL_H
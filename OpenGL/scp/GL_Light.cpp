#include "OpenGL/Header/GL_Light.h"

Light::Light(float intensity, glm::vec3 color)
{
	this->intensity = intensity;
	this->color = color;
}

PointLight::PointLight(std::string Light_Name , glm::vec3 position, float intensity, glm::vec3 color,
	float constant, float linear, float quadratic) : Light(intensity, color)
{
	this->Name = Light_Name;
	this->position = position;
	this->constant = constant;
	this->linear = linear;
	this->quadratic = quadratic;
}

void PointLight::setPosition(glm::vec3 position)
{
	this->position = position;
}

void PointLight::sendToShader(Shader& program)
{
	program.setVec3f(this->position, "pointLight.position");
	program.set1f(this->intensity, "pointLight.intensity");
	program.setVec3f(this->color, "pointLight.color");
	program.set1f(this->constant, "pointLight.constant");
	program.set1f(this->linear, "pointLight.linear");
	program.set1f(this->quadratic, "pointLight.quadratic");
}
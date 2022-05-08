#include "OpenGL/Header/GL_Camera.h"

void Camera::updateCameraVectors()
{
	this->front.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
	this->front.y = sin(glm::radians(this->pitch));
	this->front.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));

	this->front = glm::normalize(this->front);
	this->right = glm::normalize(glm::cross(this->front, this->worldUp));
	this->up = glm::normalize(glm::cross(this->right, this->front));
}

Camera::Camera(float position_x, float position_y, float position_z
	, float direction_x, float direction_y, float direction_z, 
	float worldUp_x, float worldUp_y, float worldUp_z)
{
	glm::vec3 position = glm::vec3(position_x, position_y, position_z);
	glm::vec3 direction = glm::vec3(direction_x, direction_y, direction_z);
	glm::vec3 worldUp = glm::vec3(worldUp_x, worldUp_y, worldUp_z);
	this->ViewMatrix = glm::mat4(1.f);

	this->movementSpeed = 3.f;
	this->sensitivity = 5.f;

	this->worldUp = worldUp;
	this->position = position;
	this->right = glm::vec3(0.f);
	this->up = worldUp;

	this->pitch = 0.f;
	this->yaw = -90.f;
	this->roll = 0.f;

	this->updateCameraVectors();
}

const glm::mat4 Camera::getViewMatrix()
{
	this->updateCameraVectors();

	this->ViewMatrix = glm::lookAt(this->position, this->position + this->front, this->up);

	return this->ViewMatrix;
}

const glm::vec3 Camera::getPosition() const
{
	return this->position;
}

void Camera::move(float x, float y, float z)
{
	this->position += this->front * x;
	this->position += this->up * y;
	this->position += this->right * z;
}

void Camera::updateMouseInput(const float& dt, const double& offsetX, const double& offsetY)
{
	//Update pitch yaw and roll
	this->pitch += static_cast<GLfloat>(offsetY) * this->sensitivity * dt;
	this->yaw += static_cast<GLfloat>(offsetX) * this->sensitivity * dt;

	if (this->pitch > 80.f)
		this->pitch = 80.f;
	else if (this->pitch < -80.f)
		this->pitch = -80.f;

	if (this->yaw > 360.f || this->yaw < -360.f)
		this->yaw = 0.f;
}

void Camera::updateInput(const float& dt, const int direction, const double& offsetX, const double& offsetY)
{
	this->updateMouseInput(dt, offsetX, offsetY);
}
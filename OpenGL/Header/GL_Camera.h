#ifndef GL_CAMERA_H_
#define GL_CAMERA_H_

#include <Windows.h>
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Interface/ICamera.h"

enum direction { FORWARD = 0, BACKWARD, LEFT, RIGHT };

class Camera : public ICamera
{
private:
	glm::mat4 ViewMatrix;

	GLfloat movementSpeed;
	GLfloat sensitivity;

	glm::vec3 worldUp;
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 right;
	glm::vec3 up;

	GLfloat pitch;
	GLfloat yaw;
	GLfloat roll;

	void updateCameraVectors();
public:
	Camera(float position_x, float position_y, float position_z
		, float direction_x, float direction_y, float direction_z,
		float worldUp_x, float worldUp_y, float worldUp_z);
	~Camera() {}

	//Accessors
	const glm::mat4 getViewMatrix();
	const glm::vec3 getPosition() const;

	//Functions
	void move(float x, float y, float z) override;
	void updateMouseInput(const float& dt, const double& offsetX, const double& offsetY) override;
	void updateInput(const float& dt, const int direction, const double& offsetX, const double& offsetY) override;
};
#endif // !GL_CAMERA_H_
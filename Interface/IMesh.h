#ifndef IMESH_H
#define IMESH_H

class IMesh
{
public:
	virtual void setPosition(float position_x, float position_y, float position_z) = 0;
	virtual void setRotation(float rotation_x, float rotation_y, float rotation_z) = 0;
	virtual void setScale(float scale_x, float scale_y, float scale_z) = 0;

	virtual void move(float position_x, float position_y, float position_z) = 0;
	virtual void rotate(float rotation_x, float rotation_y, float rotation_z) = 0;
	virtual void SelfRotate(float _x, float _y, float _z) = 0;
	virtual void scaleUp(float scale_x, float scale_y, float scale_z) = 0;

	virtual void Change_text_image(glm::vec2 Left_Up_point, glm::vec2 Left_Down_point,
		glm::vec2 Right_Down_point, glm::vec2 Right_Up_point) = 0;
};

#endif // !IMESH_H
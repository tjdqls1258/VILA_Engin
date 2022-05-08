#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include <glm/glm.hpp>

#include <glm/vec3.hpp>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace glm;

class Transform
{
public:
	vec3 Position = vec3(0,0,0);
	vec3 Orgin = vec3(0, 0, 0);
	vec3 Rotation = vec3(0, 0, 0);
	vec3 Scale = vec3(1, 1, 1);

	void SetPostion(vec3 vec);
	void SetScale(vec3 vec);
	void SetRotation(vec3 vec);

	void AddPostion(vec3 vec);
	void AddScale(vec3 vec);
	void AddRotation(vec3 vec);
};

#endif // !_TRANSFORM_H_



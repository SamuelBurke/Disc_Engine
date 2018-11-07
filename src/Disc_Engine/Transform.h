#ifndef DISC_ENGINE_TRANSFORM_H
#define DISC_ENGINE_TRANSFORM_H

#define GLM_FORCE_CTOR_INT
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Component.h"

namespace Disc_Engine
{

class Transform : public Component
{
public:
	void OnInit();

	void Translate(glm::vec3 _value);
	void Rotate(glm::vec3 _value);
	void Scale(glm::vec3 _value);

	void SetLocalPosition(glm::vec3 _position);
	void SetLocalRotation(glm::vec3 _rotation);
	void SetLocalScale(glm::vec3 _scale);

private:
	glm::vec3 m_localPosition;
	glm::vec3 m_localRotation;
	glm::vec3 m_localScale;

	//TESTING\\
	

};

}
#endif // !DISC_ENGINE_TRANSFORM_H
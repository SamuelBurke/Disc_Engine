#ifndef DISC_ENGINE_TRANSFORM_H
#define DISC_ENGINE_TRANSFORM_H

#define GLM_FORCE_CTOR_INT
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Component.h"

namespace Disc_Engine
{

class Transform : public Component // Inherits from component, attached to anything that needs to move or rotate.
{
public:
	void OnInit();

	void Translate(glm::vec3 _value);
	void Rotate(glm::vec3 _value);
	void Scale(glm::vec3 _value);

	void SetPosition(glm::vec3 _position);
	void SetRotation(glm::vec3 _rotation); 
	void SetScale(glm::vec3 _scale);
	glm::vec3 GetPosition();
	glm::vec3 GetRotation();
	glm::vec3 GetScale();

private:

	glm::vec3 m_position;
	glm::vec3 m_rotation;
	glm::vec3 m_scale;

};

}
#endif // !DISC_ENGINE_TRANSFORM_H
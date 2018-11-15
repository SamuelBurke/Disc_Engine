#ifndef DISC_ENGINE_CAMERA_H
#define DISC_ENGINE_CAMERA_H

#define GLM_FORCE_CTOR_INT

#include "Component.h"
#include "Input.h"
#include "Transform.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

namespace Disc_Engine
{

class Camera : public Component
{
public:
	void OnInit();
	void OnTick();

	glm::mat4 GetProjection();
	glm::mat4 GetView();
	//glm::mat4 GetModel();

private:
	glm::mat4 m_projectionMatrix;
	glm::mat4 m_viewMatrix;
	
	float m_radius;
	float m_near;
	float m_far;

	Input m_input;
	Transform m_transform;
};

}

#endif // !DISC_ENGINE_CAMERA_H

#ifndef DISC_ENGINE_CAMERA_H
#define DISC_ENGINE_CAMERA_H

#define GLM_FORCE_CTOR_INT

#include "Component.h"
#include "Input.h"

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

private:
	void OnDisplay();

	glm::vec3 m_cameraPos;
	glm::vec3 m_cameraTarget;
	glm::vec3 m_cameraDirection;

	glm::vec3 m_up;
	glm::vec3 m_cameraRight;
	glm::vec3 m_cameraUp;


	//glm::mat4 m_viewMatrix;
	glm::mat4 m_projMatrix;
	



	float m_radius;

	float m_cameraX;
	float m_cameraZ;


	Input m_input;
};

}

#endif // !DISC_ENGINE_CAMERA_H

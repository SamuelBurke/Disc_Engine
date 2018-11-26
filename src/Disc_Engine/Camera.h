#ifndef DISC_ENGINE_CAMERA_H
#define DISC_ENGINE_CAMERA_H

#define GLM_FORCE_CTOR_INT

#include "Component.h"
#include "Input.h"
#include "Transform.h"
#include "Window.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

namespace Disc_Engine
{

class Camera : public Component // Camera inherits from Component, attached to its own Entity.
{
public:
	void OnInit(); // Overrides the virtual function in Component.
	void OnTick(float _deltaTime); // Overrides the virtual function in Component.

	glm::mat4 GetProjection(); // Returns the projection matrix.
	glm::mat4 GetView(); // Returns the view matrix.

private:
	glm::mat4 m_projectionMatrix;
	glm::mat4 m_viewMatrix;
	
	float m_radius; // Variables for the projection matrix.
	float m_near;
	float m_far;

	float m_cameraSpeed;

	glm::vec3 m_cameraFront;
	glm::vec3 m_cameraRight;
	glm::vec3 m_cameraUp;

	Input m_input;
	Window m_window;
	Transform m_transform;
};

}

#endif // !DISC_ENGINE_CAMERA_H

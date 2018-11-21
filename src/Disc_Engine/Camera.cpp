#include "Camera.h"
#include "Input.h"
#include "Core.h"

#include <iostream>

using namespace Disc_Engine;

constexpr float CAMERA_SPEED = 0.25f;
constexpr float CAMERA_SENSITIVTY = 1.0f;

void Camera::OnInit()
{
	m_radius = 45.0f;
	m_near = 0.1f;
	m_far = 100.0f;

	m_transform.SetPosition(glm::vec3(0.0f, 0.0f, 10.0f));
	m_transform.SetRotation(glm::vec3(0, 0, 0));

	m_cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	m_cameraUp = glm::vec3(1.0f, 0.0f, 0.0f);
	m_cameraRight = glm::vec3(0.0f, 1.0f, 0.0f);

	m_projectionMatrix = glm::perspective(glm::radians(m_radius), (float)Window::GetWidth() / (float)Window::GetHeight(), m_near, m_far);
}


void Camera::OnTick(float _deltaTime)
{
	m_input.Update();

	float speed = CAMERA_SPEED; // Speed is reset to CAMERA_SPEED each frame. Prevents speed exponentially increasing as it's doubled by the follwing if statement.
	
	if (m_input.isKeyPressed(SDL_SCANCODE_LSHIFT)) { speed = speed * 2; } // Speed is used to fetch the camera speed, and will double if 'LSHIFT' is pressed.

	glm::vec3 cameraPos = m_transform.GetPosition();
	m_viewMatrix = glm::lookAt(cameraPos, cameraPos + m_cameraFront, m_cameraUp);
	

	// Speed is used to multiply with the Translate function
	//if (m_input.isKeyPressed(SDL_SCANCODE_W)) {	m_transform.Translate( m_cameraFront * speed);}

	//if (m_input.isKeyPressed(SDL_SCANCODE_S)) { m_transform.Translate(-m_cameraFront * speed);}

	//if (m_input.isKeyPressed(SDL_SCANCODE_A)) { m_transform.Translate( m_cameraRight * speed);}

	//if (m_input.isKeyPressed(SDL_SCANCODE_D)) { m_transform.Translate(-m_cameraRight * speed);}

	//if (m_input.isKeyPressed(SDL_SCANCODE_E)) { m_transform.Translate( m_cameraUp * speed);}

	//if (m_input.isKeyPressed(SDL_SCANCODE_Q)) { m_transform.Translate(-m_cameraUp * speed);}



	if (m_input.isKeyPressed(SDL_SCANCODE_W)) {	m_transform.Rotate(m_cameraUp * CAMERA_SENSITIVTY * _deltaTime); }

	if (m_input.isKeyPressed(SDL_SCANCODE_S)) { m_transform.Rotate(-m_cameraUp * CAMERA_SENSITIVTY * _deltaTime);}

	if (m_input.isKeyPressed(SDL_SCANCODE_A)) { m_transform.Rotate( m_cameraRight * CAMERA_SENSITIVTY * _deltaTime);}

	if (m_input.isKeyPressed(SDL_SCANCODE_D)) { m_transform.Rotate(-m_cameraRight * CAMERA_SENSITIVTY * _deltaTime);}



																									
	m_viewMatrix = glm::translate(glm::mat4(1), m_transform.GetPosition());
	m_viewMatrix = glm::rotate(m_viewMatrix, m_transform.GetRotation().x, glm::vec3(1, 0, 0));
	m_viewMatrix = glm::rotate(m_viewMatrix, m_transform.GetRotation().y, glm::vec3(0, 1, 0));
	m_viewMatrix = glm::inverse(m_viewMatrix);
}

glm::mat4 Camera::GetProjection()
{
	return m_projectionMatrix;
}

glm::mat4 Camera::GetView()
{
	return m_viewMatrix;
}
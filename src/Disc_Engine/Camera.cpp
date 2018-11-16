#include "Camera.h"
#include "Input.h"

#include <iostream>

using namespace Disc_Engine;

constexpr float CAMERA_SPEED = 0.25f;
constexpr float CAMERA_SENSITIVTY = 0.0008f;

void Camera::OnInit()
{
	m_radius = 45.0f;
	m_near = 0.1f;
	m_far = 100.0f;

	//m_screenCenter = { Window::GetWidth() / Window::GetHeight() };

	m_transform.SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));
	m_transform.SetRotation(glm::vec3(0, 0, 0));

	m_projectionMatrix = glm::perspective(glm::radians(m_radius), (float)Window::GetWidth() / (float)Window::GetHeight(), m_near, m_far);
}


void Camera::OnTick()
{
	m_input.Update();

	float speed = CAMERA_SPEED; // Speed is reset to CAMERA_SPEED each frame. Prevents speed exponentially increasing as it's doubled by the follwing if statement.
	
	if (m_input.isKeyPressed(SDL_SCANCODE_LSHIFT)) { speed = speed * 2; } // Speed is used to fetch the camera speed, and will double if 'LSHIFT' is pressed.

	// Speed is used to multiply with the Translate function
	if (m_input.isKeyPressed(SDL_SCANCODE_W)) {	m_transform.Translate(glm::vec3(  0.0f,  0.0f, -1.0f ) *speed);}

	if (m_input.isKeyPressed(SDL_SCANCODE_S)) { m_transform.Translate(glm::vec3(  0.0f,  0.0f,  1.0f ) *speed);}

	if (m_input.isKeyPressed(SDL_SCANCODE_A)) { m_transform.Translate(glm::vec3( -1.0f,  0.0f,  0.0f ) *speed);}

	if (m_input.isKeyPressed(SDL_SCANCODE_D)) { m_transform.Translate(glm::vec3(  1.0f,  0.0f,  0.0f ) *speed);}

	if (m_input.isKeyPressed(SDL_SCANCODE_Q)) { m_transform.Translate(glm::vec3(  0.0f, -1.0f,  0.0f ) *speed);}

	if (m_input.isKeyPressed(SDL_SCANCODE_E)) { m_transform.Translate(glm::vec3(  0.0f,  1.0f,  0.0f ) *speed);}


	//if (m_input.isMouseMoving()) 
	//{
	//	glm::vec3 angle = -m_input.GetMouseRotAngle();

	//	m_transform.Rotate(glm::vec3(angle.x, angle.y, 0.0f) * CAMERA_SENSITIVTY);
	//}

	glm::vec2 screenCenter = glm::vec2{ Window::GetWidth(), Window::GetHeight() } / glm::vec2(2, 2);

	if (glm::distance(m_input.GetMousePosition(), screenCenter) > 50)
	{
		SDL_WarpMouseInWindow(m_window.GetWindow(), m_window.GetWidth() / 2, m_window.GetHeight() / 2);
		m_input.SetPrevMousePos(screenCenter);
	}

	else
	{
		glm::vec3 angle = -m_input.GetMouseRotAngle();

		m_transform.Rotate(glm::vec3(angle.x, angle.y, 0.0f) * CAMERA_SENSITIVTY);


		m_input.SetPrevMousePos(m_input.GetMousePosition());
	}

	



	//
	//if (m_input.isKeyPressed(SDL_SCANCODE_UP))    { m_transform.Rotate(glm::vec3(0.0f, 0.0f, 0.0f)); }

	//if (m_input.isKeyPressed(SDL_SCANCODE_DOWN))  { m_transform.Rotate(glm::vec3(0.0f, 0.0f, 0.0f)); }	

	//if (m_input.isKeyPressed(SDL_SCANCODE_LEFT))  { m_transform.Rotate(glm::vec3(0.0f, 0.0f, 0.0f)); }

	//if (m_input.isKeyPressed(SDL_SCANCODE_RIGHT)) { m_transform.Rotate(glm::vec3(0.0f, 0.0f, 0.0f)); }

																									
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
#include "Camera.h"
#include "Input.h"
#include "Window.h"

#include <iostream>

using namespace Disc_Engine;

void Camera::OnInit()
{
	m_radius = 45.0f;
	m_near = 0.1f;
	m_far = 100.0f;

	m_modelMatrix = glm::mat4(1.0f);
	m_viewMatrix = glm::inverse(m_modelMatrix);
	m_projectionMatrix = glm::perspective(glm::radians(m_radius), (float)Window::GetWidth() / (float)Window::GetHeight(), m_near, m_far);
}

void Camera::OnTick()
{
	m_input.Update();

	if (m_input.isKeyPressed(SDL_SCANCODE_W))
	{
		m_radius += 1.0f;
	}

	else if (m_input.isKeyPressed(SDL_SCANCODE_S))
	{
		m_radius -= 1.0f;
	}
}

glm::mat4 Camera::GetProjection()
{
	return m_projectionMatrix;
}

glm::mat4 Camera::GetView()
{
	return m_viewMatrix;
}

glm::mat4 Camera::GetModel()
{
	return m_modelMatrix;
}
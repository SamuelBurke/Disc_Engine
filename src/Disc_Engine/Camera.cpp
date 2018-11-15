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

	m_transform.SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));
	m_transform.SetRotation(glm::vec3(0, 0, 0));

	m_projectionMatrix = glm::perspective(glm::radians(m_radius), (float)Window::GetWidth() / (float)Window::GetHeight(), m_near, m_far);
}

void Camera::OnTick()
{
	m_input.Update();

	if (m_input.isKeyPressed(SDL_SCANCODE_W)) {	m_transform.Translate(glm::vec3(0.0f, 0.0f, -0.1f)); }
	if (m_input.isKeyPressed(SDL_SCANCODE_S)) { m_transform.Translate(glm::vec3(0.0f, 0.0f, 0.1f));}
	if (m_input.isKeyPressed(SDL_SCANCODE_A)) { m_transform.Translate(glm::vec3(-0.1f, 0.0f, 0.0f)); }
	if (m_input.isKeyPressed(SDL_SCANCODE_D)) { m_transform.Translate(glm::vec3(0.1f, 0.0f, 0.0f));}
	
	if (m_input.isKeyPressed(SDL_SCANCODE_UP)) { m_transform.Rotate(glm::vec3(0.01f, 0.0f, 0.0f)); }
	if (m_input.isKeyPressed(SDL_SCANCODE_DOWN)) { m_transform.Rotate(glm::vec3(-0.01f, 0.0f, 0.0f)); }					
	if (m_input.isKeyPressed(SDL_SCANCODE_LEFT)) { m_transform.Rotate(glm::vec3(0.0f, 0.01f, 0.0f)); }
	if (m_input.isKeyPressed(SDL_SCANCODE_RIGHT)) { m_transform.Rotate(glm::vec3(0.0f, -0.01f, 0.0f)); }
																									
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

//glm::mat4 Camera::GetModel()
//{
//	return m_modelMatrix;
//}
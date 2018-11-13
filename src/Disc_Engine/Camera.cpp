#include "Camera.h"
#include "Window.h"
#include "Input.h"

#include <iostream>

using namespace Disc_Engine;

void Camera::OnInit()
{
	m_projMatrix = glm::perspective(glm::radians(45.0f), (float)Window::GetWidth() / (float)Window::GetHeight(), 0.1f, 100.0f);
}

void Camera::OnTick()
{
	m_input.Update();

	if (m_input.isKeyPressed(SDL_SCANCODE_W))
	{
		std::cout << "W Pressed" << std::endl;
	}
	else
	{
		std::cout << "---" << std::endl;
	}
}

void Camera::OnDisplay()
{
	//May not be necessary...Not sure yet
}

glm::mat4 Camera::GetProjection()
{
	return m_projMatrix;
}
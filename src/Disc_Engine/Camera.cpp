#include "Camera.h"

#include <iostream>

using namespace Disc_Engine;

void Camera::OnInit()
{
	m_cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	m_cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	m_cameraDirection = glm::normalize(m_cameraPos - m_cameraTarget);

	m_up = glm::vec3(0.0f, 1.0f, 0.0f);
	m_cameraRight = glm::normalize(glm::cross(m_up, m_cameraDirection));
	m_cameraUp = glm::cross(m_cameraDirection, m_cameraRight);

	m_view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f),
					  	 glm::vec3(0.0f, 0.0f, 0.0f),
						 glm::vec3(0.0f, 1.0f, 0.0f));


	//m_input.Init();
}

void Camera::OnTick()
{
	//m_input.MouseUpdate();

}

void Camera::OnDisplay()
{
	//May not be necessary...Not sure yet
}
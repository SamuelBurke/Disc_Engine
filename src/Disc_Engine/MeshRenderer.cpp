#include "Core.h"
#include "Camera.h"
#include "MeshRenderer.h"
#include "Shader.h"
#include "Transform.h"
#include "Goldwell/Player.h"

#include <iostream>

#include <GL/glew.h>
#include <glm/ext.hpp>

using namespace Disc_Engine;

void MeshRenderer::OnInit()
{
	m_angle = 0;

	m_shader = std::make_shared<Shader>("../resources/shaders/shader.vert", "../resources/shaders/shader.frag");

	m_shader->SetUniform("in_Projection", GetCore()->GetComponent<Camera>()->GetProjection());
}

void MeshRenderer::OnTick(float _deltaTime)
{
	m_shader->SetUniform("in_View", GetCore()->GetComponent<Camera>()->GetView());

	m_angle += 100.0f * _deltaTime;
}


void MeshRenderer::OnDisplay()
{
	glm::mat4 cube(1.0f);

	glm::vec3 cubePos = GetCore()->GetComponent<Transform>()->GetPosition();
	cube = glm::translate(cube, cubePos);

	m_shader->SetUniform("in_Model", cube);
	m_shader->SetUniform("in_Texture", GetCore()->GetComponent<Player>()->GetTexture());

	m_shader->Draw(*GetCore()->GetComponent<Player>()->GetModel());



	//glm::mat4 map(1.0f);
	//glm::vec3 mapPos = GetCore()->GetComponent<Transform>()->GetPosition();
	//map = glm::translate(map, mapPos);

	//glm::vec3 mapRot = GetCore()->GetComponent<Transform>()->GetRotation();
	//map = glm::rotate(map, glm::radians(90.0f), mapRot);

	//m_shader->SetUniform("in_Model", map);
	//m_shader->SetUniform("in_Texture", GetCore()->GetComponent<World>()->GetTexture());

	//m_shader->Draw(*GetCore()->GetComponent<World>()->GetModel());

}

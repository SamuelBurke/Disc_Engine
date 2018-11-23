#include "Player.h"
#include "Disc_Engine/Core.h"
#include "Disc_Engine/Camera.h"

#include <iostream>
#include <glm/ext.hpp>

void Player::OnInit()
{
	m_angle = 0;

	m_debugCube = std::make_shared<Disc_Engine::VertexArray>("../resources/models/cube.obj");
	m_defaultTexture = std::make_shared<Disc_Engine::Texture>("../resources/textures/default.png");
	m_shader = std::make_shared<Disc_Engine::Shader>("../resources/shaders/shader.vert", "../resources/shaders/shader.frag");
	
}

void Player::OnTick(float _deltaTime)
{
	m_shader->SetUniform("in_Projection", GetCore()->GetComponent<Disc_Engine::Camera>()->GetProjection());
	m_shader->SetUniform("in_View", GetCore()->GetComponent<Disc_Engine::Camera>()->GetView());


	m_angle += 100.0f * _deltaTime;
}

void Player::OnDisplay()
{
	glm::mat4 cube(1.0f);
	
	GetCore()->GetComponent<Disc_Engine::Transform>()->SetPosition(glm::vec3(0.0f, 0.0f, -10.0f));
	glm::vec3 cubePos = GetCore()->GetComponent<Disc_Engine::Transform>()->GetPosition();
	cube = glm::translate(cube, cubePos);

	GetCore()->GetComponent<Disc_Engine::Transform>()->SetRotation(glm::vec3(-1, 0, 1));
	glm::vec3 cubeRot = GetCore()->GetComponent<Disc_Engine::Transform>()->GetRotation();
	cube = glm::rotate(cube, glm::radians(m_angle), cubeRot);

	m_shader->SetUniform("in_Model", cube);
	m_shader->SetUniform("in_Texture", m_defaultTexture);
	m_shader->Draw(*m_debugCube);
}
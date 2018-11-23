#include "Player.h"
#include "Disc_Engine/Core.h"
#include "Disc_Engine/Camera.h"

#include <iostream>
#include <glm/ext.hpp>

void Player::OnInit()
{
	m_speed = glm::vec3(1.0f, 0.0f, 0.0f);

	m_debugCube = std::make_shared<Disc_Engine::VertexArray>("../resources/models/cube.obj");
	m_defaultTexture = std::make_shared<Disc_Engine::Texture>("../resources/textures/default.png");	


	//GetCore()->GetComponent<Disc_Engine::Transform>()->SetPosition(glm::vec3(0.0f, 0.0f, -10.0f));
	//GetCore()->GetComponent<Disc_Engine::Transform>()->SetRotation(glm::vec3(-1, 0, 1));
}

void Player::OnTick(float _deltaTime)
{
	GetCore()->GetComponent<Disc_Engine::Transform>()->Translate(glm::vec3(m_speed) * _deltaTime);

	//m_angle += 100.0f * _deltaTime;
}

void Player::OnDisplay()
{
}

std::shared_ptr<Disc_Engine::Texture> Player::GetTexture()
{
	return m_defaultTexture;
}

std::shared_ptr<Disc_Engine::VertexArray> Player::GetModel()
{
	return m_debugCube;
}
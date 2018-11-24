#include "Player.h"
#include "Disc_Engine/Core.h"
#include "Disc_Engine/Camera.h"

#include <iostream>
#include <glm/ext.hpp>

void Player::Init(std::shared_ptr<Disc_Engine::Transform> _transform)
{
	m_transform = _transform;

	m_speed = 5.0f;
	m_direction = glm::vec3(0.0f, 1.0f, 0.0f);

	m_debugCube = std::make_shared<Disc_Engine::VertexArray>("../resources/models/cube.obj");
	m_defaultTexture = std::make_shared<Disc_Engine::Texture>("../resources/textures/default.png");	

	m_transform->SetPosition(glm::vec3(0.0f, 0.0f, -18.0f));
	m_playerParts.push_back(1);

	//GetCore()->GetComponent<Disc_Engine::Transform>()->SetPosition(glm::vec3(0.0f, 0.0f, -10.0f));
	//GetCore()->GetComponent<Disc_Engine::Transform>()->SetRotation(glm::vec3(-1, 0, 1));
}

void Player::Update(float _deltaTime)
{
	m_input.Update();
	//GetCore()->GetComponent<Disc_Engine::Transform>()->Translate(glm::vec3(m_speed) * _deltaTime);

	//m_angle += 100.0f * _deltaTime;

	//GetCore()->GetComponent<Disc_Engine::Transform>()->Translate(glm::vec3(m_speed) * _deltaTime);

	if (m_input.isKeyPressed(SDL_SCANCODE_W) || m_input.isKeyPressed(SDL_SCANCODE_UP)) { m_direction = glm::vec3(0.0f, 1.0f, 0.0f);  }

	if (m_input.isKeyPressed(SDL_SCANCODE_S) || m_input.isKeyPressed(SDL_SCANCODE_DOWN)) { m_direction = glm::vec3(0.0f, -1.0f, 0.0f); }

	if (m_input.isKeyPressed(SDL_SCANCODE_D) || m_input.isKeyPressed(SDL_SCANCODE_RIGHT)) { m_direction = glm::vec3(1.0f, 0.0f, 0.0f);  }

	if (m_input.isKeyPressed(SDL_SCANCODE_A) || m_input.isKeyPressed(SDL_SCANCODE_LEFT)) { m_direction = glm::vec3(-1.0f, 0.0f, 0.0f); }

	if (m_input.isKeyPressed(SDL_SCANCODE_SPACE))
	{
		m_playerParts.push_back(1);
	}

	std::cout << m_playerParts.size() << std::endl;

	m_transform->Translate(m_direction * m_speed * _deltaTime);
}



std::shared_ptr<Disc_Engine::Texture> Player::GetTexture()
{
	return m_defaultTexture;
}

std::shared_ptr<Disc_Engine::VertexArray> Player::GetModel()
{
	return m_debugCube;
}
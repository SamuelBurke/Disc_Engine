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

	m_playerPos = glm::vec3(0.0f, 0.0f, -18.0f);
	m_transform->SetPosition(m_playerPos);

	m_playerParts.push_back(1);
}

void Player::Update(float _deltaTime)
{
	m_input.Update();

	if (m_input.isKeyPressed(SDL_SCANCODE_W) || m_input.isKeyPressed(SDL_SCANCODE_UP)) { m_direction = glm::vec3(0.0f, 1.0f, 0.0f);  }

	if (m_input.isKeyPressed(SDL_SCANCODE_S) || m_input.isKeyPressed(SDL_SCANCODE_DOWN)) { m_direction = glm::vec3(0.0f, -1.0f, 0.0f); }

	if (m_input.isKeyPressed(SDL_SCANCODE_D) || m_input.isKeyPressed(SDL_SCANCODE_RIGHT)) { m_direction = glm::vec3(1.0f, 0.0f, 0.0f);  }

	if (m_input.isKeyPressed(SDL_SCANCODE_A) || m_input.isKeyPressed(SDL_SCANCODE_LEFT)) { m_direction = glm::vec3(-1.0f, 0.0f, 0.0f); }

	m_playerPos = glm::vec3(m_direction * m_speed * _deltaTime);
	m_transform->Translate(m_playerPos);

	//m_transform->Translate(m_direction * m_speed * _deltaTime);
}

glm::vec3 Player::GetPosition()
{
	return m_transform->GetPosition();
}

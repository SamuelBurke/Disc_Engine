#include "Player.h"
#include "Disc_Engine/Core.h"

#include <iostream>
//#include <GL/glew.h>
#include <glm/ext.hpp>

void Player::OnInit()
{
	m_angle = 0;
}

void Player::OnTick(float _deltaTime)
{
	m_angle += 100.0f * _deltaTime;

	std::cout << m_angle << std::endl;
}

void Player::OnDisplay()
{
	glm::mat4 cube(1.0f);
	
	GetCore()->GetComponent<Disc_Engine::Transform>()->SetPosition(glm::vec3(0.0f, 0.0f, -10.0f));
}
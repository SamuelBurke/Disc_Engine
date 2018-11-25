#include "World.h"

#include "Disc_Engine/Core.h"
#include "Disc_Engine/VertexArray.h"
#include "Disc_Engine/Texture.h"
#include "Disc_Engine/AABBcollision.h"

#include <iostream>

void World::OnInit()
{
	m_transform = GetTransform();
	m_collider = GetCollider();
	//m_map = std::make_shared<Disc_Engine::VertexArray>("../resources/models/map.obj");
	//m_mapTexture = std::make_shared<Disc_Engine::Texture>("../resources/textures/default.png");

	//TODO:::Move To Resources Handler
	m_debugCube = std::make_shared<Disc_Engine::VertexArray>("../resources/models/cube.obj");
	m_defaultTexture = std::make_shared<Disc_Engine::Texture>("../resources/textures/default.png");
	
	m_player.Init(m_transform);
	m_fruit.Init(m_transform);
}

void World::OnTick(float _deltaTime)
{
	m_player.Update(_deltaTime);
	//m_fruit.Update(_deltaTime);

	glm::vec3 a = GetPlayerPosition();
	glm::vec3 b = m_fruit.GetFruitPosition();

	if (m_collider->IsColliding(a, b))
	{
		m_player.AddSnakePart();

		//m_fruit.OnSpawn();
		//std::cout << "called" << std::endl;
	}
	
}

std::shared_ptr<Disc_Engine::VertexArray> World::GetModel()
{
	return m_debugCube;
}

std::shared_ptr<Disc_Engine::Texture> World::GetTexture()
{
	return m_defaultTexture;
}

glm::vec3 World::GetPlayerPosition()
{
	return m_player.GetPlayerPosition();
}
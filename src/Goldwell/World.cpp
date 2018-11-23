#include "World.h"

#include "Disc_Engine/Core.h"
#include "Disc_Engine/Transform.h"

#include <iostream>

void World::OnInit()
{
	m_map = std::make_shared<Disc_Engine::VertexArray>("../resources/models/map.obj");
	m_mapTexture = std::make_shared<Disc_Engine::Texture>("../resources/textures/default.png");

	GetCore()->GetComponent<Disc_Engine::Transform>()->SetPosition(glm::vec3(0.0f, 0.0f, -10.0f));
}



void World::OnTick(float _deltaTime)
{
	//std::cout << "world called" << std::endl;
}

std::shared_ptr<Disc_Engine::VertexArray> World::GetModel()
{
	return m_map;
}

std::shared_ptr<Disc_Engine::Texture> World::GetTexture()
{
	return m_mapTexture;
}
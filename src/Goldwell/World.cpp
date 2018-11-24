#include "World.h"

#include "Disc_Engine/Core.h"
#include "Disc_Engine/VertexArray.h"
#include "Disc_Engine/Texture.h"

#include <iostream>

void World::OnInit()
{
	m_map = std::make_shared<Disc_Engine::VertexArray>("../resources/models/map.obj");
	m_mapTexture = std::make_shared<Disc_Engine::Texture>("../resources/textures/default.png");

	m_transform = GetTransform();
	//GetCore()->GetComponent<Disc_Engine::Transform>()->SetPosition(glm::vec3(0.0f, 0.0f, -10.0f));

	m_player.Init(m_transform);

}

void World::OnTick(float _deltaTime)
{
	m_player.Update(_deltaTime);

	//m_transform->Translate(glm::vec3(1.0f, 0.0f, 0.0f) * _deltaTime);
}

std::shared_ptr<Disc_Engine::VertexArray> World::GetModel()
{
	return m_player.GetModel();
}

std::shared_ptr<Disc_Engine::Texture> World::GetTexture()
{
	return m_player.GetTexture();
}

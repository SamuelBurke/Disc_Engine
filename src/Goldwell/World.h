#ifndef WORLD_H
#define WORLD_H

#include "Disc_Engine/Component.h"

#include "Player.h"
#include "Fruit.h"

#include <memory>

class Disc_Engine::VertexArray;
class Disc_Engine::Texture;

class World : public Disc_Engine::Component
{

public:
	void OnInit();

	void OnTick(float _deltaTime);

	std::shared_ptr<Disc_Engine::VertexArray> GetModel();
	std::shared_ptr<Disc_Engine::Texture> GetTexture();

	glm::vec3 GetPlayerPosition();

private:
	Player m_player;
	Fruit m_fruit;

	std::shared_ptr<Disc_Engine::Transform> m_transform;
	std::shared_ptr<Disc_Engine::AABBCollision> m_collider;

	std::shared_ptr<Disc_Engine::VertexArray> m_debugCube;
	std::shared_ptr<Disc_Engine::Texture> m_defaultTexture;

};

#endif // !WORLD_H

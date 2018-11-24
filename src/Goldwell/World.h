#ifndef WORLD_H
#define WORLD_H

#include "Disc_Engine/Component.h"

#include "Player.h"

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

private:
	std::shared_ptr<Disc_Engine::VertexArray> m_map;
	std::shared_ptr<Disc_Engine::Texture> m_mapTexture;

	Player m_player;

	std::shared_ptr<Disc_Engine::Transform> m_transform;
};

#endif // !WORLD_H

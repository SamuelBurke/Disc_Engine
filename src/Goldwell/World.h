#ifndef WORLD_H
#define WORLD_H

#include "Disc_Engine/VertexArray.h"
#include "Disc_Engine/Texture.h"
#include "Disc_Engine/Component.h"

#include <memory>

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
};

#endif // !WORLD_H

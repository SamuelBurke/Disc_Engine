#ifndef PLAYER_H
#define PLAYER_H

#include "Disc_Engine/Component.h"
#include "Disc_Engine/Transform.h"

#include "Disc_Engine/VertexArray.h"
#include "Disc_Engine/Texture.h"
#include "Disc_Engine/Shader.h"

#include <memory>

class VertexArray;
class Texture;

class Player : public Disc_Engine::Component
{
public:
	void OnInit();

private:
	void OnTick(float _deltaTime);
	void OnDisplay();

	float m_angle;

	//TESTING\\	

	std::shared_ptr<Disc_Engine::VertexArray> m_debugCube;
	std::shared_ptr<Disc_Engine::Texture> m_defaultTexture;
	std::shared_ptr<Disc_Engine::Shader> m_shader;
};

#endif // !PLAYER_H

#ifndef PLAYER_H
#define PLAYER_H

#include "Disc_Engine/VertexArray.h"
#include "Disc_Engine/Texture.h"
#include "Disc_Engine/Shader.h"

#include "Disc_Engine/Input.h"
#include "Disc_Engine/Transform.h"

#include "Disc_Engine/Component.h"


#include <memory>

class Player
{
public:
	void Init(std::shared_ptr<Disc_Engine::Transform> _transform);
	void Update(float _deltaTime);

	std::shared_ptr<Disc_Engine::Texture> GetTexture();
	std::shared_ptr<Disc_Engine::VertexArray> GetModel();

private:
	float m_speed;
	glm::vec3 m_direction;

	//float m_angle;

	Disc_Engine::Input m_input;

	//TESTING\\	
	std::shared_ptr<Disc_Engine::VertexArray> m_debugCube;
	std::shared_ptr<Disc_Engine::Texture> m_defaultTexture;






	std::shared_ptr<Disc_Engine::Transform> m_transform;
	
};

#endif // !PLAYER_H

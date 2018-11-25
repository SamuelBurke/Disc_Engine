#ifndef PLAYER_H
#define PLAYER_H

#include "Disc_Engine/VertexArray.h"
#include "Disc_Engine/Texture.h"
#include "Disc_Engine/Shader.h"

#include "Disc_Engine/Input.h"
#include "Disc_Engine/Transform.h"

#include "Disc_Engine/Component.h"

#include <vector>
#include <memory>

class Player
{
public:
	void Init(std::shared_ptr<Disc_Engine::Transform> _transform);
	void Update(float _deltaTime);

	void AddSnakePart();

	glm::vec3 GetPlayerPosition();

private:
	float m_speed;
	glm::vec3 m_direction;
	glm::vec3 m_playerPos;

	Disc_Engine::Input m_input;

	std::vector<int> m_playerParts;

	std::shared_ptr<Disc_Engine::Transform> m_transform;
	
};

#endif // !PLAYER_H

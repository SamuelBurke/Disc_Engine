#include "AABBcollision.h"

#include <iostream>

using namespace Disc_Engine;

void AABBCollision::Collide()
{
	m_colliding = false;

	if (IsColliding(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0)))
	{
		//TODO:::SPAWN APPLES WHEN COLLIDED
		m_colliding = true;
	}
}

bool AABBCollision::IsColliding(glm::vec3 _a, glm::vec3 _b)
{
	m_colX = false;
	m_colY = false;
	m_colZ = false;

	if (_a.x < _b.x)
	{
		if (_a.x + 2 > _b.x - 1) { m_colX = true; } // 2 & 1 are offset values, so the collision is not pixel perfect.
	}
	else if (_b.x + 2 > _a.x - 1) { m_colX = true;}

	if (_a.y < _b.y)
	{
		if (_a.y + 2 > _b.y - 1) { m_colY = true; }
	}
	else if (_b.y + 2 > _a.y - 1) { m_colY = true; }

	if (_a.z < _b.z)
	{
		if (_a.z + 2 > _b.z - 1) { m_colZ = true; }
	}
	else if (_b.z + 2 > _a.z - 1) { m_colZ = true;}

	if (m_colX && m_colY && m_colZ)
	{
		std::cout << "collided" << std::endl;
		return true;
	}
	
}
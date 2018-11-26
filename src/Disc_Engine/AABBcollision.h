#ifndef DISC_ENGINE_AABBCOLLISION_H
#define DISC_ENGINE_AABBCOLLISION_H

#include "Component.h"

#include <glm/glm.hpp>

namespace Disc_Engine
{
	
class AABBCollision : public Component // AABBCollision, inherits from component to be added to the player and fruit.
{
public:
	void Collide();
	bool IsColliding(glm::vec3 _a, glm::vec3 _b); // Called to check if a and b collide with each other.

private:

	bool m_colX; // boolean variables for each coordinate to check collision.
	bool m_colY;
	bool m_colZ;

	bool m_colliding;
};

}
#endif // !DISC_ENGINE_AABBCOLLISION_H

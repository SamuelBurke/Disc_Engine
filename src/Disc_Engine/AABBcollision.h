#ifndef DISC_ENGINE_AABBCOLLISION_H
#define DISC_ENGINE_AABBCOLLISION_H

#include "Component.h"

#include <glm/glm.hpp>

namespace Disc_Engine
{
	
class AABBCollision : public Component
{
public:
	void Collide();
	bool IsColliding(glm::vec3 _a, glm::vec3 _b);

private:

	bool m_colX;
	bool m_colY;
	bool m_colZ;

	bool m_colliding;
};

}
#endif // !DISC_ENGINE_AABBCOLLISION_H

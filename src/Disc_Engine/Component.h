#ifndef DISC_ENGINE_COMPONENT_H
#define DISC_ENGINE_COMPONENT_H

#include <memory>

namespace Disc_Engine
{
class Entity; // Forward declaration used to make shared pointers of various types, without including the entire header file.
class Core;
class ResourcesHandler;
class Transform;
class AABBCollision;

class Component
{
	friend class Entity; // Allows Entity to use Component's private variables and functions.

public:
	virtual ~Component();

	std::shared_ptr<Core> GetCore(); // Returns pointers to these classes, for use around the engine.
	std::shared_ptr<Entity> GetEntity();
	std::shared_ptr<Transform> GetTransform();
	std::shared_ptr<AABBCollision> GetCollider();
	static std::shared_ptr<ResourcesHandler> GetResourcesHandler();

private:
	std::weak_ptr<Entity> m_entity; // Stores parent entity.
	bool m_began;

	virtual void OnInit(); // Abstract functions, can be overridden by other components.
	virtual void OnBegin();
	virtual void OnTick(float _deltaTime);
	virtual void OnDisplay();

};
}
#endif // !DISC_ENGINE_COMPONENT_H

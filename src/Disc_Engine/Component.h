#ifndef DISC_ENGINE_COMPONENT_H
#define DISC_ENGINE_COMPONENT_H

#include <memory>

namespace Disc_Engine
{
class Entity;
class Core;
class ResourcesHandler;
class Transform;

class Component
{
	friend class Entity;

public:
	virtual ~Component();

	std::shared_ptr<Core> GetCore();
	std::shared_ptr<Entity> GetEntity();
	static std::shared_ptr<ResourcesHandler> GetResourcesHandler();

	std::shared_ptr<Transform> GetTransform();

private:
	std::weak_ptr<Entity> m_entity;
	bool m_began;

	virtual void OnInit();
	virtual void OnBegin();
	virtual void OnTick(float _deltaTime);
	virtual void OnDisplay();

};
}
#endif // !DISC_ENGINE_COMPONENT_H

#ifndef DISC_ENGINE_COMPONENT_H
#define DISC_ENGINE_COMPONENT_H

#include <memory>

namespace Disc_Engine
{
class Entity;

class Component
{
	friend class Entity;

public:
	virtual ~Component();

private:
	std::weak_ptr<Entity> m_entity;
	bool m_begin;

	virtual void OnInit();
	virtual void OnBegin();
	virtual void OnTick();
	virtual void OnDisplay();

};
}
#endif // !DISC_ENGINE_COMPONENT_H

#include "Entity.h"

using namespace Disc_Engine;

void Entity::Tick()
{
	for (std::vector<std::shared_ptr<Component> >::iterator it = m_components.begin(); it != m_components.end(); it++)
	{
		if (!(*it)->m_began)
		{
			(*it)->OnBegin();
			(*it)->m_began = true;
		}

		(*it)->OnTick();
	}
}

void Entity::Display()
{
	for (std::vector<std::shared_ptr<Component> >::iterator it = m_components.begin(); it != m_components.end(); it++)
	{
		(*it)->OnDisplay();
	}
}

std::shared_ptr<Core> Entity::GetCore()
{
	return m_core.lock();
}
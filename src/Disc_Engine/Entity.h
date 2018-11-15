#ifndef DISC_ENGINE_ENTITY_H
#define DISC_ENGINE_ENTITY_H

#include "Component.h"

#include <memory> 
#include <vector>

#define ADDCOMPONENT \
	std::shared_ptr<T> rtn = std::make_shared<T>(); \
	rtn->m_entity = m_self; \
	rtn->m_began = false;   \
	m_components.push_back(rtn);

namespace Disc_Engine 
{

class Core; /* Forward declaration of Core, @ see line 24.
			 

/*! An Entity stores the raw game objects within the engine.
    Each entity will be made up of potentially multiple components. */
class Entity 
{	
	friend class Core; // Allows private functions in Entity to be accessed by Core.

public:
	template <typename T>
	std::shared_ptr<T> GetComponent()
	{
		for (size_t i = 0; i < m_components.size(); i++)
		{
			std::shared_ptr<T> currentComponent = std::dynamic_pointer_cast<T>(m_components.at(i));

			if (currentComponent)
			{
				return currentComponent;
			}
		}

		return false;
		throw std::exception();
	}

	template <typename T>
	std::shared_ptr<T> AddComponent()
	{
		ADDCOMPONENT
		rtn->OnInit();

		return rtn;	
	}

	template <typename T, typename A>
	std::shared_ptr<T> AddComponent(A _a)
	{
		ADDCOMPONENT
		rtn->OnInit(_a);

		return rtn;
	}

	template <typename T, typename A, typename B>
	std::shared_ptr<T> AddComponent(A _a, B _b)
	{
		ADDCOMPONENT
		rtn->OnInit(_a, _b);

		return rtn;
	}

	std::shared_ptr<Core> GetCore();

private:
	//! Function to be called every frame. Updates every entity.
	void Tick(); 

	//! Function to be called after everything has been updated as is ready to display
	void Display();
	
	std::vector<std::shared_ptr<Component>> m_components;
	std::weak_ptr<Entity> m_self; // Stores a pointer to the current entity, set in Core.cpp @ line 101.
	std::weak_ptr<Core>   m_core; // stores a pointer to the core, set in the Core.cpp @ line 102.
};
}

#endif // !DISC_ENGINE_ENTITY_H
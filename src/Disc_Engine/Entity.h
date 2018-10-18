#ifndef DISC_ENGINE_ENTITY_H
#define DISC_ENGINE_ENTITY_H

#include "Component.h"

#include <memory> 
#include <vector>

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
			std::shared_ptr<T> test = std::dynamic_pointer_cast<T>(m_components.at(i));

			if (test)
			{
				return test;
			}
		}

		throw std::exception();
	}

	template <typename T>
	std::shared_ptr<T> AddComponent()
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();
		rtn->m_entity = m_self;
		rtn->m_begin = false;
		m_components.push_back(rtn);

		rtn->OnInit();

		return rtn;	
	}

	std::shared_ptr<Core> GetCore();

private:
	//! Function to be called every frame. Updates every entity.
	void Tick(); 

	//! Function to be caled after everything has been updated as is ready to display
	void Display();
	

	std::vector<std::shared_ptr<Component>> m_components;
	std::weak_ptr<Entity> m_self; // Stores a pointer to the current entity, set in Core.cpp @ line 36.
	std::weak_ptr<Core>   m_core; // stores a pointer to the core, set in the Core.cpp @ line 37.
};
}

#endif // !DISC_ENGINE_ENTITY_H
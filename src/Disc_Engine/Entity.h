#ifndef DISC_ENGINE_ENTITY_H
#define DISC_ENGINE_ENTITY_H

#include <memory> 

namespace Disc_Engine 
{

class Core; /* Forward declaration of Core, @ see line 24.
			 

/*! An Entity stores the raw game objects within the engine.
    Each entity will be made up of potentially multiple components. */
class Entity 
{	
	friend class Core; // Allows private functions in Entity to be accessed by Core.
private:
	//! Function to be called every frame. Updates every entity.
	void Tick(); 

	//! Function to be caled after everything has been updated as is ready to display
	void Display();
	


	std::weak_ptr<Entity> m_self; // Stores a pointer to the current entity, set in Core.cpp @ line 36.
	std::weak_ptr<Core>   m_core; // stores a pointer to the core, set in the Core.cpp @ line 37.
};
}

#endif // !DISC_ENGINE_ENTITY_H
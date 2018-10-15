#ifndef DISC_ENGINE_ENTITY_H
#define DISC_ENGINE_ENTITY_H

#include <memory> 

namespace Disc_Engine 
{

class Core; 

/*! An Entity stores the raw game objects within the engine.
    Each entity will be made up of potentially multiple components. */
class Entity 
{	
	friend class Core; //declares Core as a 'friend class' - Allows private functions in Entity to be accessed by Core.
private:
	void Tick(); //function to be called every frame. Updates every entity.
	void Display(); //function to be called after everything has updated and is ready to display (always after Tick).
	
	//std::weak_ptr<Core> m_core;
	std::weak_ptr<Entity> m_self; //weak pointer variable - stores a pointer to the current entity.
};
}

#endif // !DISC_ENGINE_ENTITY_H
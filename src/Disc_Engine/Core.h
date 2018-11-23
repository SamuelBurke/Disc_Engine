#ifndef DISC_ENGINE_CORE_H
#define DISC_ENGINE_CORE_H

#include <AL/al.h>
#include <AL/alc.h>

#include <memory>     
#include <vector>     

#include "Entity.h"
#include "Environment.h"
#include "Input.h"
#include "Window.h"

#include "Goldwell/World.h"

namespace Disc_Engine // Encapsulates the class within the engine namespace. For the sake of efficient programming.
{
//class Entity;	 /* Forward declaration of Entity allows usage of <Entity>
				  //@ see line 29 */

/*! Creates the Core class of the engine. The core contains all entities used within the game engine. */
class Core
{
public:
	//! First function called in core, for initialisation. 
	static std::shared_ptr<Core> Init(); 

	//! Function containing the main loop of the core. "Begins" the engine. 
	void Begin();

	//! Function called to end the engine's execution. 
	void End();

	//! Function used to add an entity to the vector of entities. @ see line 32
	std::shared_ptr<Entity> AddEntity();

	template <typename T>
	std::shared_ptr<T> GetComponent();
	
private:
	bool m_quit; //Boolean variable - Which is set to false when the engine is running.

	std::vector<std::shared_ptr<Entity>> m_entities; //Stores all the entities within the core.
	std::weak_ptr<Core> m_self; //Stores a pointer of the core itself.

	Window m_window;
	Input m_input;
	Environment m_environment;
	ALCdevice* m_device;
	ALCcontext* m_context;


	World m_world;
};

template<typename T>
inline std::shared_ptr<T> Core::GetComponent()
{
	for (std::shared_ptr<Entity> e : m_entities)
	{
		if (e->GetComponent<T>())
		{
			return e->GetComponent<T>();
		}
	}

	throw std::exception();
}

}

#endif // !DISC_ENGINE_CORE_H

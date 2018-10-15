#ifndef DISC_ENGINE_CORE_H
#define DISC_ENGINE_CORE_H

#include <memory>     //For use of shared & weak pointers.
#include <vector>     //For use of vectors.

namespace Disc_Engine //Encapsulates the class within the engine namespace. For the sake of efficient programming.
{
class Entity;         /*Forward declaration of Entity allows usage of <Entity>
					  @ see line 26
					  */

/*! Creates the Core class of the engine. The core contains all entities used within the game engine. */
class Core 
{
public:
	//! First function called in core, for initialisation.
	static std::shared_ptr<Core> Init(); 

	//! Function containing the main loop of the core. "Begins" the engine.
	void Begin();
	
private:
	bool m_quit; //Boolean variable - Which is set to false when the engine is running.

	std::vector<std::shared_ptr<Entity>> m_entities; //Stores all the entities within the core.
	std::weak_ptr<Core> m_self; //Stores a pointer of the core itself.
};
}

#endif // !DISC_ENGINE_CORE_H

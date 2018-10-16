#include "Core.h" //include original class
#include "Entity.h" //allows access to the entities' tick to be called in Begin

#include <iostream>

using namespace Disc_Engine;

std::shared_ptr<Core> Core::Init() //called at the beginning of main().
{
	std::shared_ptr<Core> rtn = std::make_shared<Core>(); //want to return a shared pointer of core
	rtn->m_quit = false;                                  //to the main, to then call entity through
	rtn->m_self = rtn;                                    //core, and component through entity.

	return rtn; //return our pointer to core back to main.
}

void Core::Begin() //called at the end of main() - Here is where the main loop will be.
{
	while (!m_quit)
	{
		for (std::vector<std::shared_ptr<Entity> >::iterator it = m_entities.begin(); it != m_entities.end(); it++)
		{
			(*it)->Tick();
		}
	}
}

void Core::End() /// TO BE DONE: CALL IF SDL_QUIT = TRUE
{
	m_quit = true;
}

std::shared_ptr<Entity> Core::AddEntity() 
{
	std::shared_ptr<Entity> rtn = std::make_shared<Entity>(); // rtn is a pointer to the entity sent through this function.
	m_entities.push_back(rtn);                                // Adds the rtn to the vector of entities.
	rtn->m_self = rtn;                                        // Sets the weak pointer to 'self' in Entity to the rtn.
	rtn->m_core = m_self;                                     // Sets the weak pointer to 'core' in Entity to the self set above.

	return rtn;
}

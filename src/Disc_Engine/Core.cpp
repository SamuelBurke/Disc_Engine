#include "Core.h" //include original class
#include "Entity.h" //allows access to the entities' tick to be called in Begin

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
	m_quit = false;
	while (!m_quit)
	{
		for (std::vector<std::shared_ptr<Entity> >::iterator it = m_entities.begin(); it != m_entities.end(); it++)
		{
			(*it)->Tick();
		}
	}
}

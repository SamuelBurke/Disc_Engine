#include "Core.h" //include original class
#include "Entity.h" //allows access to the entities' tick to be called in Begin
#include "MeshRenderer.h"

#include <iostream>

using namespace Disc_Engine;

std::shared_ptr<Core> Core::Init() //called at the beginning of main().
{
	std::shared_ptr<Core> rtn = std::make_shared<Core>(); //want to return a shared pointer of core
	rtn->m_quit = true;                                   //to the main, to then call entity through
	rtn->m_self = rtn;                                    //core, and component through entity.

	rtn->m_window.InitWin();                              //call the initialisation of the SDL window.
	rtn->m_input.Init();

	rtn->m_device = alcOpenDevice(NULL);
	if (!rtn->m_device)
	{
		throw std::exception();
	}

	rtn->m_context = alcCreateContext(rtn->m_device, NULL);
	if (!rtn->m_context)
	{
		alcCloseDevice(rtn->m_device);
		throw std::exception();
	}

	if (!alcMakeContextCurrent(rtn->m_context))
	{
		alcDestroyContext(rtn->m_context);
		alcCloseDevice(rtn->m_device);
		throw std::exception();
	}

	//remember to close after use
	//alcMakeContextCurrent(NULL)
	//alcDestroyContext(m_context);
	//alcCloseDevice(m_device);



	return rtn; //return our pointer to core back to main.
}

void Core::Begin() //called at the end of main() - Here is where the main loop will be.
{
	//std::shared_ptr<Entity> ent = AddEnt();
	//std::shared_ptr<MeshRenderer> tri = ent->AddComponent<MeshRenderer>();

	m_quit = false;

	while (!m_quit)
	{
		SDL_Event e = { 0 };

		while (SDL_PollEvent(&e))          
		{
			if (e.type == SDL_QUIT)
			{
				End();
			}
		}

		for (std::vector<std::shared_ptr<Entity> >::iterator it = m_entities.begin(); it != m_entities.end(); it++)
		{
			(*it)->Tick(); //(*it) dereferences the shared ptr - How to use iterators with smart pointers.
		}



		m_window.ClearBuff(); // Clear the buffer before the entities are displayed.

		for (std::vector<std::shared_ptr<Entity> >::iterator it = m_entities.begin(); it != m_entities.end(); it++)
		{
			(*it)->Display();
			
		}

		m_window.SwapWin();

	}
}

void Core::End() 
{
	m_quit = true;

	alcMakeContextCurrent(NULL);
	alcDestroyContext(m_context);
	alcCloseDevice(m_device);
}

std::shared_ptr<Entity> Core::AddEntity() 
{
	std::shared_ptr<Entity> rtn = std::make_shared<Entity>(); // rtn is a pointer to the entity sent through this function.
	m_entities.push_back(rtn);                                // Adds the rtn to the vector of entities.
	rtn->m_self = rtn;                                        // Sets the weak pointer to 'self' in Entity to the rtn.
	rtn->m_core = m_self;                                     // Sets the weak pointer to 'core' in Entity to the self set above.

	return rtn;
}

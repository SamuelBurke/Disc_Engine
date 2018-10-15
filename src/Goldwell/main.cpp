//------------------------------------------------//
//Example of a CES design (Component Entity System)
//This main.cpp uses the include below to access the engine.
//The engine is made up of a core, providing a hub for the rest of the engine to exist within.
//Within the core are the various entities that will exist in the engine/game.
//Within each entity are various components to be dealt with in certain ways.
//From core, we iterate through the entities, and in the entities we iterate through the components.
//---------------------------------------------------------------------------------------------------//

#include <Disc_Engine/Disc_Engine.h> //allows the use of Engine elements in our game main. Core, Entity etc.

#include <memory> //std::shared_ptr, std::weak_ptr.

//class Example : public Disc_Engine::Component
//{
//public:
//	blah blah 
//};

int main()
{
	std::shared_ptr<Disc_Engine::Core> core = Disc_Engine::Core::Init(); //call the initialsation of core.

	core->Begin(); //begin the core of the engine.

	return 0;
}
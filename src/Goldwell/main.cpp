//------------------------------------------------//
//Example of a CES design (Component Entity System)
//This main.cpp uses the include below to access the engine.
//The engine is made up of a core, providing a hub for the rest of the engine to exist within.
//Within the core are the various entities that will exist in the engine/game.
//Within each entity are various components to be dealt with in certain ways.
//From core, we iterate through the entities, and in the entities we iterate through the components.
//---------------------------------------------------------------------------------------------------//

#include <Disc_Engine/Disc_Engine.h> //allows the use of Engine elements in our game main. Core, Entity etc.
#include "World.h"

#include <iostream>
#include <memory>

int main()
{
	std::shared_ptr<Disc_Engine::Core> core = Disc_Engine::Core::Init(); //call the initialsation of core.
	std::shared_ptr<Disc_Engine::Entity> user = core->AddEntity();
	std::shared_ptr<Disc_Engine::Entity> camera = core->AddEntity();
	
	std::shared_ptr<Disc_Engine::Camera> cam = camera->AddComponent<Disc_Engine::Camera>();
	std::shared_ptr<Disc_Engine::Transform> trans = camera->AddComponent<Disc_Engine::Transform>();

	std::shared_ptr<Disc_Engine::Transform> transform = user->AddComponent<Disc_Engine::Transform>();
	std::shared_ptr<Disc_Engine::AABBCollision> collider = user->AddComponent<Disc_Engine::AABBCollision>();
	std::shared_ptr<World> world = user->AddComponent<World>();
	std::shared_ptr<Disc_Engine::MeshRenderer> meshRenderer = user->AddComponent<Disc_Engine::MeshRenderer>();

	std::shared_ptr<Disc_Engine::Audio> audio = std::make_shared<Disc_Engine::Audio>("../resources/audio/wiimusic.ogg");
	audio->Play();

	core->Begin(); //begin the core of the engine.

	return 0;
}
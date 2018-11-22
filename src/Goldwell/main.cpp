//------------------------------------------------//
//Example of a CES design (Component Entity System)
//This main.cpp uses the include below to access the engine.
//The engine is made up of a core, providing a hub for the rest of the engine to exist within.
//Within the core are the various entities that will exist in the engine/game.
//Within each entity are various components to be dealt with in certain ways.
//From core, we iterate through the entities, and in the entities we iterate through the components.
//---------------------------------------------------------------------------------------------------//

#include <Disc_Engine/Disc_Engine.h> //allows the use of Engine elements in our game main. Core, Entity etc.
#include "Player.h"

#include <iostream>

//class Example : public Disc_Engine::Component
//{
//public:
//	blah blah
//};

//class TestScreen : public Disc_Engine::Component
//{
//public:
//	void OnInit(std::string _colour){}
//	void OnBegin() {}
//	void OnTick(){}
//	void OnDisplay(){}
//};

int main()
{
	//std::shared_ptr<Player> player = std::make_shared<Player>();

	std::shared_ptr<Disc_Engine::Core> core = Disc_Engine::Core::Init(); //call the initialsation of core.
	std::shared_ptr<Disc_Engine::Entity> ent = core->AddEntity();



	std::shared_ptr<Player> player = ent->AddComponent<Player>();






	//std::shared_ptr<Disc_Engine::ResourcesHandler> resource;
	//std::shared_ptr<Disc_Engine::Shader> shader = resource->Create<Disc_Engine::Shader>();
	//std::shared_ptr<Disc_Engine::Shader> shader = Disc_Engine::Component::GetResourcesHandler()->Load

	//std::shared_ptr<Disc_Engine::Texture> texture = Disc_Engine::Component::GetResourcesHandler()->Load<Disc_Engine::Texture>("../resources/textures/default.png");

	std::shared_ptr<Disc_Engine::Audio> audio = std::make_shared<Disc_Engine::Audio>("../resources/audio/dixie_horn.ogg");
	//audio->Play();

	//Gives the entity 'models' both a MeshRenderer component, and a Transform component.
	std::shared_ptr<Disc_Engine::MeshRenderer> meshRenderer = ent->AddComponent<Disc_Engine::MeshRenderer>();
	
	//std::shared_ptr<Disc_Engine::Transform> transform = ent->AddComponent<Disc_Engine::Transform>();


	std::shared_ptr<Disc_Engine::Entity> camera = core->AddEntity();
	std::shared_ptr<Disc_Engine::Camera> cam = camera->AddComponent<Disc_Engine::Camera>();
	std::shared_ptr<Disc_Engine::Transform> transform = camera->AddComponent<Disc_Engine::Transform>();

	core->Begin(); //begin the core of the engine.

	return 0;
}
#include "Component.h"
#include "Entity.h"
#include "ResourcesHandler.h"

#include <iostream>

using namespace Disc_Engine;

Component::~Component()
{
}

void Component::OnInit()
{

}

void Component::OnBegin()
{
}

void Component::OnTick(float _deltaTime)
{
}

void Component::OnDisplay()
{
}

std::shared_ptr<Entity> Component::GetEntity()
{
	return m_entity.lock();
}


std::shared_ptr<Core> Component::GetCore()
{
	return GetEntity()->GetCore();
}

std::shared_ptr<ResourcesHandler> Component::GetResourcesHandler()
{
	return std::shared_ptr<ResourcesHandler>();
}

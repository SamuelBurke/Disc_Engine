#include "Component.h"
#include "Entity.h"

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

void Component::OnTick()
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
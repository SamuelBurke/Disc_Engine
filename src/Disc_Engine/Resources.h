#ifndef DISC_ENGINE_RESOURCES_H
#define DISC_ENGINE_RESOURCES_H

#include "Resource.h"

#include <memory>
#include <list>

namespace Disc_Engine
{

class Resources
{
private:
	std::list<std::shared_ptr<Resource>> m_resources;
};

}
#endif // !DISC_ENGINE_RESOURCES_H

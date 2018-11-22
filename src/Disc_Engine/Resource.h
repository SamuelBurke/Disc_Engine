#ifndef DISC_ENGINE_RESOURCE_H
#define DISC_ENGINE_RESOURCE_H

#include <memory>
#include <string>

namespace Disc_Engine
{
class ResourcesHandler;

class Resource
{
friend class ResourcesHandler;

private:
	std::string m_filePath;
};


}
#endif // !DISC_ENGINE_RESOURCE_H

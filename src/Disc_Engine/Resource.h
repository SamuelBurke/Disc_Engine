#ifndef DISC_ENGINE_RESOURCE_H
#define DISC_ENGINE_RESOURCE_H

#include <string>

namespace Disc_Engine
{

class Resource
{
	friend class Mesh;
	friend class Texture;
private:
	std::string m_filePath;
};

}
#endif // !DISC_ENGINE_RESOURCE_H

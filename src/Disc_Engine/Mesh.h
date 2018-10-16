#ifndef DISC_ENGINE_MESH_H
#define DISC_ENGINE_MESH_H

#include "Resource.h"

namespace Disc_Engine
{

class Mesh : public Resource
{
public:
	~Mesh();
private:
	static std::shared_ptr<Mesh> Generate();
	static std::shared_ptr<Mesh> Load(std::string _filePath);
};

}

#endif // !DISC_ENGINE_MESH_H
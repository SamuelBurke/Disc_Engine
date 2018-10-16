#ifndef DISC_ENGINE_TEXTURE_H
#define DISC_ENGINE_TEXTURE_H

#include "Resource.h"

namespace Disc_Engine
{

class Texture : public Resource
{
public:
	static std::shared_ptr<Texture> Generate(unsigned int _width, unsigned int _height);
	static std::shared_ptr<Texture> Load(std::string _filePath);
};

}

#endif // !DISC_ENGINE_TEXTURE_H

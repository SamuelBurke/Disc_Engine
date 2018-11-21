#ifndef DISC_ENGINE_TEXTURE_H
#define DISC_ENGINE_TEXTURE_H

#include "Resource.h"

#include <GL/glew.h>
#include <glm/glm.hpp>

namespace Disc_Engine
{

class Texture : public Resource
{
public:
	//static std::shared_ptr<Texture> Generate(unsigned int _width, unsigned int _height);
	//static std::shared_ptr<Texture> Load(std::string _filePath);

	//Texture(std::string _file);
	void Load(std::string _file);
	glm::vec2 GetSize();
	GLuint GetID();

private:
	GLuint m_id;
	glm::vec2 m_size;

};

}

#endif // !DISC_ENGINE_TEXTURE_H

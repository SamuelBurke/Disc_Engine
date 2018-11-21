#ifndef DISC_ENGINE_SHADER_H
#define DISC_ENGINE_SHADER_H

#include "Resource.h"

#include <string>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>

namespace Disc_Engine
{
class VertexArray;
class Texture;

struct Sampler
{
	GLint m_id;
	std::shared_ptr<Texture> texture;
};

class Shader : public Resource
{
public:
	//Shader(std::string _vertex, std::string _fragment);
	void Load(std::string _vertex, std::string _fragment);
	void Draw(VertexArray& _vertexArray);

	void SetUniform(std::string _uniform, glm::vec4 _value);
	void SetUniform(std::string _uniform, float _value);
	void SetUniform(std::string _uniform, glm::mat4 _value);
	void SetUniform(std::string _uniform, std::shared_ptr<Texture> _texture);

	GLuint GetID();

private:
	GLuint m_id;
	std::vector<Sampler> m_samplers;

};
}

#endif // !DISC_ENGINE_SHADER_H

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

//namespace Disc_Engine
//{
//class VertexArray;
//
//class Shader : public Resource
//{
//public:
//	Shader(const char* _vertPath, const char* _fragPath);
//	//void Use();
//	void Draw(VertexArray &_vertArray);
//	void SetUniform(std::string _uniform, glm::vec4 _value);
//	void SetUniform(std::string _uniform, float _value);
//	void SetUniform(std::string _uniform, glm::mat4 _value);
//
//	GLuint GetID();
//
//private:
//	void CheckCompilerErrors(unsigned int _shader, std::string _type);
//
//	GLuint m_id;
//
//	std::string m_vertCode;
//	std::string m_fragCode;
//
//	std::ifstream m_vShaderFile;
//	std::ifstream m_fShaderFile;
//
//	std::stringstream m_vShaderStream, m_fShaderStream;
//
//	const char* m_vShaderCode;
//	const char* m_fShaderCode;
//
//	//const std::shared_ptr<char> m_vShaderCode;
//	//const std::shared_ptr<char> m_fShaderCode;
//
//	unsigned int m_vert, m_frag;
//};
//
//}

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
	Shader(std::string _vertex, std::string _fragment);
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

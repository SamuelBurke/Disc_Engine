#ifndef DISC_ENGINE_SHADER_H
#define DISC_ENGINE_SHADER_H

#include "Resource.h"

#include <string>
#include <fstream>
#include <sstream>
#include <memory>

namespace Disc_Engine
{
class Shader : public Resource
{
public:
	Shader(const char* _vertPath, const char* _fragPath);

	unsigned int m_id;

	void Use();

	std::string m_vertCode;
	std::string m_fragCode;

	std::ifstream m_vShaderFile;
	std::ifstream m_fShaderFile;

	std::stringstream m_vShaderStream, m_fShaderStream;

	const char* m_vShaderCode;
	const char* m_fShaderCode;

	//const std::shared_ptr<char> m_vShaderCode;
	//const std::shared_ptr<char> m_fShaderCode;

	unsigned int m_vert, m_frag;

private:
	void CheckCompilerErrors(unsigned int _shader, std::string _type);

};

}

#endif // !DISC_ENGINE_SHADER_H

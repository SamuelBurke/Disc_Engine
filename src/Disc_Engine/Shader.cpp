#include "Shader.h"

#include <gl/glew.h>
#include <iostream>

using namespace Disc_Engine;

Shader::Shader(const char* _vertPath, const char* _fragPath)
{
	m_vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	m_fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		//open files
		m_vShaderFile.open(_vertPath);
		m_fShaderFile.open(_fragPath);

		//read the file's buffer contents into streams
		//'rdbuf' redirects the buffer contents
		m_vShaderStream << m_vShaderFile.rdbuf();
		m_fShaderStream << m_fShaderFile.rdbuf();

		//close the file handlers
		m_vShaderFile.close();
		m_fShaderFile.close();

		//convert stream into string
		m_vertCode = m_vShaderStream.str();
		m_fragCode = m_fShaderStream.str();
	}

	catch (std::ifstream::failure _e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_READ_SUCCESSFULLY" << std::endl;
	}

	m_vShaderCode = m_vertCode.c_str();
	m_fShaderCode = m_vertCode.c_str();

	//vertex shader
	m_vert = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(m_vert, 1, &m_vShaderCode, NULL);
	glCompileShader(m_vert);
	CheckCompilerErrors(m_vert, "VERTEX");

	//fragment shader
	m_frag = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(m_vert, 1, &m_fShaderCode, NULL);
	glCompileShader(m_frag);
	CheckCompilerErrors(m_frag, "FRAGMENT");

	//shader program
	m_id = glCreateProgram();
	glAttachShader(m_id, m_vert);
	glAttachShader(m_id, m_frag);
	glLinkProgram(m_id);
	CheckCompilerErrors(m_id, "PROGRAM");

	//delete shaders as they're linked into the program and aren't necessary
	glDeleteShader(m_vert);
	glDeleteShader(m_frag);
}

void Shader::Use()
{
	glUseProgram(m_id);
}

void Shader::CheckCompilerErrors(unsigned int _shader, std::string _type)
{
	int success;
	char infoLog[1024];
	if (_type != "PROGRAM")
	{
		glGetShaderiv(_shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(_shader, 1024, NULL, infoLog);
			std::cout << "ERROR: SHADER COMPILATION ERROR of type: " << _type << std::endl << infoLog << "\n -- --------- --" << std::endl;
		}
	}
	else
	{
		glGetProgramiv(_shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(_shader, 1024, NULL, infoLog);
			std::cout << "ERROR: PROGRAM LINKING ERROR of type: " << _type << std::endl << infoLog << "\n-- --------- --" << std::endl;
		}
	}
}
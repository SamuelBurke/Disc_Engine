#include "Shader.h"
#include "VertArray.h"

#include <glm/ext.hpp>

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
	glBindAttribLocation(m_id, 0, "in_Position");
	glBindAttribLocation(m_id, 1, "in_Color");

	glLinkProgram(m_id);
	CheckCompilerErrors(m_id, "PROGRAM");

	//delete shaders as they're linked into the program and aren't necessary
	glDeleteShader(m_vert);
	glDeleteShader(m_frag);
}

//void Shader::Use()
//{
//	glUseProgram(m_id);
//}

void Shader::Draw(VertArray &_vertArray)
{
	glUseProgram(m_id);
	glBindVertexArray(_vertArray.GetID());

	glDrawArrays(GL_TRIANGLES, 0, _vertArray.GetVertexCount());
	

	glBindVertexArray(0);
	glUseProgram(0);
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
	std::cout << "Program & Shader loaded successfully." << std::endl;
}

void Shader::SetUniform(std::string _uniform, glm::vec4 _value)
{
	GLint uniformID = glGetUniformLocation(m_id, _uniform.c_str());

	if (uniformID == -1)
	{
		throw std::exception();
	}

	glUseProgram(m_id);
	glUniform4f(uniformID, _value.x, _value.y, _value.z, _value.w);
	glUseProgram(0);
}

void Shader::SetUniform(std::string _uniform, float _value)
{
	GLint uniformID = glGetUniformLocation(m_id, _uniform.c_str());

	if (uniformID == -1)
	{
		throw std::exception();
	}

	glUseProgram(m_id);
	glUniform1f(uniformID, _value);
	glUseProgram(0);
}

void Shader::SetUniform(std::string _uniform, glm::mat4 _value)
{
	GLint uniformID = glGetUniformLocation(m_id, _uniform.c_str());

	if (uniformID == -1)
	{
		throw std::exception();
	}

	glUseProgram(m_id);
	glUniformMatrix4fv(uniformID, 1, GL_FALSE, glm::value_ptr(_value));
	glUseProgram(0);
}

GLuint Shader::GetID()
{
	return m_id;
}
#include "VertBuffer.h"

using namespace Disc_Engine;

VertBuffer::VertBuffer() : m_components(0), m_dirty(false)
{
	glGenBuffers(1, &m_id);

	if (!m_id)
	{
		throw std::exception();
	}
}

void VertBuffer::Add(glm::vec3 _value)
{
	if (!m_components)
	{
		m_components = 3;
	}

	if (m_components != 3)
	{
		throw std::exception();
	}

	m_data.push_back(_value.x);
	m_data.push_back(_value.y);
	m_data.push_back(_value.z);
	m_dirty = true;
}

void VertBuffer::Add(glm::vec4 _value)
{
	if (!m_components)
	{
		m_components = 4;
	}

	if (m_components != 4)
	{
		throw std::exception();
	}

	m_data.push_back(_value.x);
	m_data.push_back(_value.y);
	m_data.push_back(_value.z);
	m_data.push_back(_value.w);
	m_dirty = true;
}

int VertBuffer::GetDataSize()
{
	return m_data.size();
}

int VertBuffer::GetComponents()
{
	if (!m_components)
	{
		throw std::exception();
	}

	return m_components;
}

GLuint VertBuffer::GetID()
{
	if (m_dirty)
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_id);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * m_data.size(), &m_data.at(0), GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		m_dirty = false;
	}

	return m_id;
}

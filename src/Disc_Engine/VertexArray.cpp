#include "VertexArray.h"
#include "VertexBuffer.h"

using namespace Disc_Engine;

VertexArray::VertexArray() : m_dirty(false)
{
	glGenVertexArrays(1, &m_id);

	if (!m_id)
	{
		throw std::exception();
	}

	m_buffers.resize(10);
}

void VertexArray::SetBuffer(std::string _attribute, std::weak_ptr<VertexBuffer> _buffer)
{
	if (_attribute == "in_Position")
	{
		m_buffers.at(0) = _buffer.lock();
	}

	else if (_attribute == "in_Color")
	{
		m_buffers.at(1) = _buffer.lock();
	}

	else
	{
		throw std::exception();
	}

	m_dirty = true;
}

int VertexArray::GetVertexCount()
{
	if (!m_buffers.at(0))
	{
		throw std::exception();
	}

	return m_buffers.at(0)->GetDataSize() / m_buffers.at(0)->GetComponents();
}

GLuint VertexArray::GetID()
{
	if (m_dirty)
	{
		glBindVertexArray(m_id);

		for (size_t i = 0; i < m_buffers.size(); i++)
		{
			if (m_buffers.at(i))
			{
				glBindBuffer(GL_ARRAY_BUFFER, m_buffers.at(i)->GetID());

				glVertexAttribPointer(i, m_buffers.at(i)->GetComponents(), GL_FLOAT, GL_FALSE, 
					m_buffers.at(i)->GetComponents() * sizeof(GLfloat), (void *)0);

				glEnableVertexAttribArray(i);
			}

			else
			{
				glDisableVertexAttribArray(i);
			}
		}

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
		m_dirty = false;
	}

	return m_id;
}
#include "MeshRenderer.h"

using namespace Disc_Engine;

void MeshRenderer::Init()
{
	const GLfloat positions[] =
	{
		0.0f,  0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f
	};

	m_positionsVboId = 0;

	//create a new VBO on the GPU and bind it
	glGenBuffers(1, &m_positionsVboId);

	if (!m_positionsVboId)
	{
		throw std::exception();
	}

	glBindBuffer(GL_ARRAY_BUFFER, m_positionsVboId);
	//upload a copy of the data from memory into the new VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);
	//reset the state
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	m_vaoId = 0;

	//create a new VAO on the GPU and bind it
	glGenVertexArrays(1, &m_vaoId);

	if (!m_vaoId)
	{
		throw std::exception();
	}

	glBindVertexArray(m_vaoId);

	//bind the position VBO, assign it to a position on the bound VAO and flag it to be used.
	glBindBuffer(GL_ARRAY_BUFFER, m_positionsVboId);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void *)0);

	glEnableVertexAttribArray(0);

	//reset the state
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	m_shader = std::make_shared<Shader>("../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
}

void MeshRenderer::Display()
{
	m_shader->Use();
	glBindVertexArray(m_vaoId);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	//reset the state
	glBindVertexArray(0);
	glUseProgram(0);
}

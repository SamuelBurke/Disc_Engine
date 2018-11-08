#include "MeshRenderer.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Texture.h"

#include <iostream>

#include <GL/glew.h>
#include <glm/ext.hpp>

using namespace Disc_Engine;

void MeshRenderer::OnInit()
{

	//std::shared_ptr<VertexBuffer> positions = std::make_shared<VertexBuffer>();
	//positions->Add(glm::vec3( 0.0f,  0.5f, 0.0f));
	//positions->Add(glm::vec3(-0.5f, -0.5f, 0.0f));
	//positions->Add(glm::vec3( 0.5f, -0.5f, 0.0f));

	//std::shared_ptr<VertexBuffer> colors = std::make_shared<VertexBuffer>();
	//colors->Add(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
	//colors->Add(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
	//colors->Add(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

	//m_shape->SetBuffer("in_Position", positions);

	m_shape = std::make_shared<VertexArray>("../resources/models/teapot_pgg.obj");
	m_texture = std::make_shared<Texture>("../resources/textures/default.png");
	m_shader = std::make_shared<Shader>("../resources/shaders/shader.vert", "../resources/shaders/shader.frag");
}


void MeshRenderer::OnDisplay()
{
	m_shader->SetUniform("in_View", glm::mat4(1.0f));
	m_shader->SetUniform("in_Model", glm::mat4(1.0f));
	m_shader->SetUniform("in_Projection", glm::mat4(1.0f));
	m_shader->SetUniform("in_Texture", m_texture);
	m_shader->Draw(*m_shape);
}

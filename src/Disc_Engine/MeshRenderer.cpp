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

	//m_shape = std::make_shared<VertexArray>("../resources/models/teapot_pgg.obj");
	//m_texture = std::make_shared<Texture>("../resources/textures/default.png");

	m_angle = 0;

	m_hall = std::make_shared<VertexArray>("../resources/models/testhall.obj");
	m_hallTex = std::make_shared<Texture>("../resources/textures/testhall_tex.png");

	m_cat = std::make_shared<VertexArray>("../resources/models/testcat.obj");
	m_catTex = std::make_shared<Texture>("../resources/textures/testcat_tex.png");

	m_shader = std::make_shared<Shader>("../resources/shaders/shader.vert", "../resources/shaders/shader.frag");
}


void MeshRenderer::OnDisplay()
{
	//m_shader->SetUniform("in_View", glm::mat4(1.0f));
	//m_shader->SetUniform("in_Model", glm::mat4(1.0f));
	//m_shader->SetUniform("in_Projection", glm::mat4(1.0f));
	//m_shader->SetUniform("in_Texture", m_texture);
	//m_shader->Draw(*m_shape);

	m_shader->SetUniform("in_Projection", glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.f));

	glm::mat4 model(1.0f);
	m_shader->SetUniform("in_View", glm::inverse(model));

	//draw hall
	model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(2.0f, -2.0f, -16.0f));
	model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0, 1, 0));
	m_shader->SetUniform("in_Model", model);
	m_shader->SetUniform("in_Texture", m_hallTex);
	m_shader->Draw(*m_hall);

	//draw cat
	model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(0, -2.1f, -20.0f));
	model = glm::rotate(model, glm::radians(m_angle), glm::vec3(0, 1, 0));
	m_shader->SetUniform("in_Model", model);
	m_shader->SetUniform("in_Texture", m_catTex);
	m_shader->Draw(*m_cat);

	m_angle += 0.01f;
	//std::cout << m_angle << std::endl;
}

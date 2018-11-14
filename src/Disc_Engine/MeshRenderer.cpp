#include "Camera.h"
#include "Core.h"
#include "MeshRenderer.h"
#include "Shader.h"
#include "Texture.h"
#include "VertexArray.h"
#include "VertexBuffer.h"

#include <iostream>

#include <GL/glew.h>
#include <glm/ext.hpp>

using namespace Disc_Engine;

void MeshRenderer::OnInit()
{
	m_angle = 0;

	m_hall = std::make_shared<VertexArray>("../resources/models/testhall.obj");
	m_hallTex = std::make_shared<Texture>("../resources/textures/testhall_tex.png");

	m_cat = std::make_shared<VertexArray>("../resources/models/testcat.obj");
	m_catTex = std::make_shared<Texture>("../resources/textures/testcat_tex.png");

	m_shader = std::make_shared<Shader>("../resources/shaders/shader.vert", "../resources/shaders/shader.frag");

}

void MeshRenderer::OnTick()
{
	m_shader->SetUniform("in_Projection", GetCore()->GetEntity<Camera>()->GetProjection()); // Fetches the projection matrix from the camera component in order to set this uniform.
	m_shader->SetUniform("in_View", GetCore()->GetEntity<Camera>()->GetView()); // Fetches the view matrix from the camera component.
}


void MeshRenderer::OnDisplay()
{
	//draw hall
	//glm::mat4 hall; // declare the model variable
	//hall = GetCore()->GetEntity<Camera>()->GetModel(); // fetches the model matrix from the camera component, to be used in the lines below.
	//GetCore()->GetEntity<Transform>()->SetPosition(glm::vec3(2.0f, -2.0f, -16.0f));
	//hall = glm::translate(hall, GetCore()->GetEntity<Transform>()->GetPosition());
	//
	//GetCore()->GetEntity<Transform>()->SetRotation(glm::vec3(0, 1, 0));
	//hall = glm::rotate(hall, glm::radians(90.0f), GetCore()->GetEntity<Transform>()->GetRotation());

	//m_shader->SetUniform("in_Model", hall);
	//m_shader->SetUniform("in_Texture", m_hallTex);
	//m_shader->Draw(*m_hall);

	//draw cat
	glm::mat4 model;
	model = GetCore()->GetEntity<Camera>()->GetModel();
	GetCore()->GetEntity<Transform>()->SetPosition(glm::vec3(0, -2.1f, -20.0f));
	model = glm::translate(model, GetCore()->GetEntity<Transform>()->GetPosition());

	GetCore()->GetEntity<Transform>()->SetRotation(glm::vec3(0, 1, 0));
	model = glm::rotate(model, glm::radians(m_angle), GetCore()->GetEntity<Transform>()->GetRotation());

	m_shader->SetUniform("in_Model", model);
	m_shader->SetUniform("in_Texture", m_catTex);
	m_shader->Draw(*m_cat);

	m_angle += 0.01f;
}

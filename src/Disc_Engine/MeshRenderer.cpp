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

	m_debugCube = std::make_shared<VertexArray>("../resources/models/cube.obj");
	m_cubeTexture = std::make_shared<Texture>("../resources/textures/default.png");

	m_shader = std::make_shared<Shader>("../resources/shaders/shader.vert", "../resources/shaders/shader.frag");

}

void MeshRenderer::OnTick()
{
	m_shader->SetUniform("in_Projection", GetCore()->GetComponent<Camera>()->GetProjection()); // Fetches the projection matrix from the camera component in order to set this uniform.
	m_shader->SetUniform("in_View", GetCore()->GetComponent<Camera>()->GetView()); // Fetches the view matrix from the camera component.
}


void MeshRenderer::OnDisplay()
{
	glm::mat4 cube(1.0f);
	GetCore()->GetComponent<Transform>()->SetPosition(glm::vec3(0, 0.0f, -10.0f));
	cube = glm::translate(cube, GetCore()->GetComponent<Transform>()->GetPosition());
	
	GetCore()->GetComponent<Transform>()->SetRotation(glm::vec3(1, 0, 1));
	cube = glm::rotate(cube, glm::radians(m_angle), GetCore()->GetComponent<Transform>()->GetRotation());

	//GetCore()->GetComponent<Transform>()->SetScale(glm::vec3(10, 10, 10));
	//cube = glm::scale(cube, GetCore()->GetComponent<Transform>()->GetScale());

	m_shader->SetUniform("in_Model", cube);
	m_shader->SetUniform("in_Texture", m_cubeTexture);
	m_shader->Draw(*m_debugCube);

	m_angle += 0.8f;
}

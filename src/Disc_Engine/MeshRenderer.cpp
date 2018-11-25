#include "Core.h"
#include "Camera.h"
#include "MeshRenderer.h"
#include "Shader.h"
#include "Transform.h"
#include "Goldwell/Player.h"

#include <iostream>

#include <GL/glew.h>
#include <glm/ext.hpp>

using namespace Disc_Engine;

void MeshRenderer::OnInit()
{
	m_angle = 0;

	m_shader = std::make_shared<Shader>("../resources/shaders/shader.vert", "../resources/shaders/shader.frag");

	SetMesh(GetCore()->GetComponent<World>()->GetModel());
	SetMaterial(GetCore()->GetComponent<World>()->GetTexture());

	m_shader->SetUniform("in_Projection", GetCore()->GetComponent<Camera>()->GetProjection());
}

void MeshRenderer::OnTick(float _deltaTime)
{
	m_shader->SetUniform("in_View", GetCore()->GetComponent<Camera>()->GetView());

	m_angle += 100.0f * _deltaTime;
}

void MeshRenderer::OnDisplay()
{
	glm::mat4 cube(1.0f);

	glm::vec3 cubePos = GetCore()->GetComponent<World>()->GetPlayerPosition();
	cube = glm::translate(cube, cubePos);

	m_shader->SetUniform("in_Model", cube);
	m_shader->SetUniform("in_Texture", m_currentTexture.lock());

	m_shader->Draw(*m_currentMesh.lock());
}

void MeshRenderer::SetMesh(std::weak_ptr<VertexArray> _mesh)
{
	m_currentMesh = _mesh;
}

std::shared_ptr<VertexArray> MeshRenderer::GetMesh()
{
	return m_currentMesh.lock();
}

void MeshRenderer::SetMaterial(std::weak_ptr<Texture> _texture)
{
	m_currentTexture = _texture;
}

std::shared_ptr<Texture> MeshRenderer::GetMaterial()
{
	return m_currentTexture.lock();
}
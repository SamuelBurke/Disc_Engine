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

	m_wall = std::make_shared<VertexArray>("../resources/models/wall.obj");


	try
	{
		m_wallTexture = std::make_shared<Texture>("../resources/textures/wood.jpg");
	}

	catch(...)
	{
		m_wallTexture = std::make_shared<Texture>("../resources/textures/default.jpg");
	}



	m_shader = std::make_shared<Shader>("../resources/shaders/shader.vert", "../resources/shaders/shader.frag");
}

void MeshRenderer::OnTick(float _deltaTime)
{
	m_shader->SetUniform("in_Projection", GetCore()->GetComponent<Camera>()->GetProjection()); // Fetches the projection matrix from the camera component in order to set this uniform.
	m_shader->SetUniform("in_View", GetCore()->GetComponent<Camera>()->GetView()); // Fetches the view matrix from the camera component.

	//std::cout << _deltaTime << std::endl;
	//GetCore()->GetComponent<Transform>()->SetScale(glm::vec3(10, 10, 10));

	m_angle += 100.0f * _deltaTime;
}


void MeshRenderer::OnDisplay()
{

	//main cube
	glm::mat4 cube(1.0f);
	GetCore()->GetComponent<Transform>()->SetPosition(glm::vec3(0.0f, 0.0f, -10.0f));
	glm::vec3 cubePos = GetCore()->GetComponent<Transform>()->GetPosition();
	cube = glm::translate(cube, cubePos);

	GetCore()->GetComponent<Transform>()->SetRotation(glm::vec3(-1, 0, 1));
	glm::vec3 cubeRot = GetCore()->GetComponent<Transform>()->GetRotation();
	cube = glm::rotate(cube, glm::radians(m_angle), cubeRot);

	m_shader->SetUniform("in_Model", cube);
	m_shader->SetUniform("in_Texture", m_cubeTexture);
	m_shader->Draw(*m_debugCube);

	//second cube
	glm::mat4 secondCube(1.0f);
	GetCore()->GetComponent<Transform>()->SetPosition(glm::vec3(5.0f, 0.0f, -10.0f));
	glm::vec3 secondCubePos = GetCore()->GetComponent<Transform>()->GetPosition();
	secondCube = glm::translate(secondCube, secondCubePos);

	GetCore()->GetComponent<Transform>()->SetRotation(glm::vec3(-1, 0, 1));
	glm::vec3 secondCubeRot = GetCore()->GetComponent<Transform>()->GetRotation();
	secondCube = glm::rotate(secondCube, glm::radians(m_angle), secondCubeRot);

	m_shader->SetUniform("in_Model", secondCube);
	m_shader->SetUniform("in_Texture", m_cubeTexture);
	m_shader->Draw(*m_debugCube);





	glm::mat4 wall(1.0f);
	GetCore()->GetComponent<Transform>()->SetPosition(glm::vec3(0.0f, 0.0f, -25.0f));
	glm::vec3 wallPos = GetCore()->GetComponent<Transform>()->GetPosition();
	wall = glm::translate(wall, wallPos);

	GetCore()->GetComponent<Transform>()->SetRotation(glm::vec3(0, 1, 0));
	glm::vec3 wallRot = GetCore()->GetComponent<Transform>()->GetRotation();
	wall = glm::rotate(wall, glm::radians(90.0f), wallRot);

	m_shader->SetUniform("in_Model", wall);
	m_shader->SetUniform("in_Texture", m_wallTexture);
	m_shader->Draw(*m_wall);

}

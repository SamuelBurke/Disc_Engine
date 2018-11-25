#include "Fruit.h"

#include <iostream>

void Fruit::Init(std::shared_ptr<Disc_Engine::Transform> _transform)
{
	m_transform = _transform;

	m_fruitPos = glm::vec3(0.0f, 0.0f, 0.0f);

	//m_transform->SetPosition(glm::vec3(0.0f, 0.0f, -18.0f));
}

void Fruit::Update(float _deltaTime)
{
	//OnSpawn();
}

void Fruit::OnSpawn()
{
	int x = 0;
	int y = 0;

	x = rand() % (Disc_Engine::Window::GetWidth() - 2) + 1;
	y = rand() % (Disc_Engine::Window::GetHeight() - 2) + 1;

	//TODO:::DIVIDE X & Y BY AN OFFSET, SO THE FRUIT REMAINS ON SCREEN
	m_fruitPos = glm::vec3(x, y, 0.0f);
}

glm::vec3 Fruit::GetFruitPosition()
{
	return m_fruitPos;
}
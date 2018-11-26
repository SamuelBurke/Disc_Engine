#ifndef FRUIT_H
#define FRUIT_H

#include "Disc_Engine/Transform.h"

#include "Disc_Engine/Window.h"

class Fruit
{
public:
	void Init(std::shared_ptr<Disc_Engine::Transform> _transform);

	glm::vec3 GetFruitPosition();

	void Update(float _deltaTime);
	void OnSpawn();
private:
	glm::vec3 m_fruitPos;

	std::shared_ptr<Disc_Engine::Transform> m_transform;
};

#endif // !FRUIT_H

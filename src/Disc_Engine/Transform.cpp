#include "Transform.h"

#include <iostream>

using namespace Disc_Engine;

void Transform::OnInit()
{
	m_scale = glm::vec3(1, 1, 1);
}

void Transform::OnDisplay()
{
	//std::cout << "Transform::OnDisplay called" << std::endl;
}

void Transform::OnTick()
{
	/*std::cout << "Position: " << m_position.x << m_position.y << m_position.z << std::endl;
	std::cout << "Rotation: " << m_rotation.x << m_rotation.y << m_rotation.z << std::endl;
	std::cout << "Scale: " << m_scale.x << m_scale.y << m_scale.z << std::endl;*/


	//m_transform = m_position * m_rotation * m_scale;
}

void Transform::Translate(glm::vec3 _value)
{
	glm::translate(glm::mat4(1), glm::vec3(_value));

	//m_position += _value;

	//m_position.x += _value.x;
	//m_position.y += _value.y;
	//m_position.z += _value.z;
}

void Transform::Rotate(glm::vec3 _value)
{
	glm::rotate(glm::mat4(1), glm::radians(90.0f), glm::vec3(_value));

	//m_rotation += _value;

	//m_rotation.x += _value.x;
	//m_rotation.y += _value.y;
	//m_rotation.z += _value.z;
}

void Transform::Scale(glm::vec3 _value)
{
	glm::scale(glm::mat4(1), glm::vec3(_value));
}

void Transform::SetPosition(glm::vec3 _position)
{
	m_position = _position;
}

void Transform::SetRotation(glm::vec3 _rotation)
{
	m_rotation = _rotation;
}

void Transform::SetScale(glm::vec3 _scale)
{
	m_scale = _scale;
}

glm::vec3 Transform::GetPosition()
{
	return m_position;
}

glm::vec3 Transform::GetRotation()
{
	return m_rotation;
}

glm::vec3 Transform::GetScale()
{
	return m_scale;
}

//glm::vec3 Transform::GetTransform()
//{
//	return m_transform;
//}
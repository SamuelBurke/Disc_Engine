#include "Transform.h"

#include <iostream>

using namespace Disc_Engine;

void Transform::OnInit()
{
	glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
	glm::mat4 trans;
	trans = glm::translate(trans, glm::vec3(1.0f, 1.0f, 0.0f));

	vec = trans*vec;

	std::cout << vec.x << vec.y << vec.z << std::endl;
}

void Transform::Translate(glm::vec3 _value)
{

}

void Transform::Rotate(glm::vec3 _value)
{

}

void Transform::Scale(glm::vec3 _value)
{

}

void Transform::SetLocalPosition(glm::vec3 _position)
{
	m_localPosition = _position;
}

void Transform::SetLocalRotation(glm::vec3 _rotation)
{
	m_localRotation = _rotation;
}

void Transform::SetLocalScale(glm::vec3 _scale)
{
	m_localScale = _scale;
}
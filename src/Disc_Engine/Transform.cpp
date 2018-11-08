#include "Transform.h"

#include <iostream>

using namespace Disc_Engine;

void Transform::OnInit()
{
}

void Transform::OnDisplay()
{
	//glm::mat4 model(1.0f);
	//model = glm::translate(model, glm::vec3(2.0f, -2.0f, -16.0f));
	//model = glm::rotate(model, glm::radians(m_angle), glm::vec3(0, 1, 0));

	//m_angle += 0.1f;

	//std::cout << m_angle << std::endl;

	//m_localRotation.y += 0.5f;
	//while (m_localRotation.y > (3.14159265 * 2.0))
	//{
	//	m_localRotation.y -= (float)(3.14159265 * 2.0);
	//}

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
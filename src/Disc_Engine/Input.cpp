#include "Input.h"

#include <iostream>

using namespace Disc_Engine;

void Input::Init()
{
	//SDL_SetRelativeMouseMode(SDL_TRUE);

	//SDL_ShowCursor(SDL_DISABLE);

}

void Input::Update()
{
	//SDL_PumpEvents();
	m_currentKey = SDL_GetKeyboardState(NULL);

	//SDL_GetMouseState(&m_mouseX, &m_mouseY);
	
}

bool Input::isKeyPressed(SDL_Scancode _keyCode)
{
	
	if (m_currentKey[_keyCode])
	{
		return true;
	}
	else
	{
		return false;
	}

}

//bool Input::isMouseMoving()
//{
//
//	if (m_mouseX != m_prevMouseX || m_mouseY != m_prevMouseY)
//	{
//		m_prevMouseX = m_mouseX;
//		m_prevMouseY = m_mouseY;
//
//		SDL_GetMouseState(&m_mouseX, &m_mouseY);
//
//		return true;
//	}
//
//	else
//	{
//		SDL_GetMouseState(&m_mouseX, &m_mouseY);
//	}
//
//	return false;
//}
//
//glm::vec3 Input::GetMouseRotAngle()
//{
//	glm::vec3 rotAngle = glm::vec3 (0, 0, 0);
//
//	rotAngle.y = m_mouseX - m_prevMouseX;
//	rotAngle.x = m_mouseY - m_prevMouseY;
//
//	return rotAngle;
//}
//
//glm::vec2 Input::GetMousePosition()
//{
//	glm::vec2 mousePos = glm::vec2(0, 0);
//
//	mousePos.x = m_mouseX;
//	mousePos.y = m_mouseY;
//
//	return mousePos;
//
//}
//
//void Input::SetPrevMousePos(glm::vec2 _mousePos)
//{
//	m_prevMouseX = _mousePos.x;
//	m_prevMouseY = _mousePos.y;
//}
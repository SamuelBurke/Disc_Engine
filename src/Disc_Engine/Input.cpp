#include "Input.h"

#include <iostream>

using namespace Disc_Engine;

void Input::Init()
{
	SDL_GetKeyboardState(&m_keys);
	m_currentKeys  = new Uint8[m_keys];
	m_previousKeys = new Uint8[m_keys];

	std::memcpy(m_currentKeys, SDL_GetKeyboardState(NULL), m_keys);
	std::memcpy(m_previousKeys, m_currentKeys, m_keys);
}

void Input::Update()
{
	std::memcpy(m_previousKeys, m_currentKeys, m_keys); // copies the memory of the "currentKeys" into the "previousKeys" at the length of "keys"
	std::memcpy(m_currentKeys, SDL_GetKeyboardState(NULL), m_keys);
}

bool Input::isKeyPressed(SDL_Scancode _keyCode)
{
	return m_currentKeys[_keyCode] && !m_previousKeys[_keyCode];
}

bool Input::isKeyHeld(SDL_Scancode _keyCode)
{
	return m_currentKeys[_keyCode];
}

bool Input::isKeyReleased(SDL_Scancode _keyCode)
{
	return !m_currentKeys[_keyCode] && m_previousKeys[_keyCode];
}


void Input::End()
{
	delete[] m_currentKeys;
	delete[] m_previousKeys;
}

//void Input::Init()
//{
//}

//void Input::MouseUpdate()
//{
//	SDL_PumpEvents();
//
//	SDL_GetMouseState(&m_mouseX, &m_mouseY);
//
//	//std::cout << "MouseX: " << m_mouseX << std::endl;
//	//std::cout << "MouseY: " << m_mouseY << std::endl;
//}

//bool Input::GetKey(int _keyCode)
//{
//	//if (_keyCode == 1)
//	//{
//	//	std::cout << "true" << std::endl;
//	//	return true;
//	//}
//
//
//	for (size_t i = 0; i < m_keyCodes.size(); i++)
//	{
//		if (_keyCode == m_keyCodes.at(i))
//		{
//			return m_keyCodes.at(i);
//			break;
//		}
//	}
//}
//
//bool Input::GetKeyUp(int _keyCode)
//{
//	//SAME AS ABOVE::CHANGE LATER
//	for (size_t i = 0; i < m_keyCodes.size(); i++)
//	{
//		if (_keyCode == m_keyCodes.at(i))
//		{
//			return m_keyCodes.at(i);
//			break;
//		}
//	}
//}
//
//bool Input::GetKeyDown(int _keyCode)
//{
//	//SAME AS ABOVE::CHANGE LATER
//	for (size_t i = 0; i < m_keyCodes.size(); i++)
//	{
//		if (_keyCode == m_keyCodes.at(i))
//		{
//			return m_keyCodes.at(i);
//			break;
//		}
//	}
//}
#include "Input.h"

#include <iostream>

using namespace Disc_Engine;

void Input::Init()
{
}

void Input::Update()
{
	SDL_PumpEvents();
	SDL_GetMouseState(&m_mouseX, &m_mouseY);
	m_currentKey = SDL_GetKeyboardState(NULL);


	//std::cout << "X: " << m_mouseX << std::endl;
	//std::cout << "Y: " << m_mouseY << std::endl;
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

//void Input::Init()
//{
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
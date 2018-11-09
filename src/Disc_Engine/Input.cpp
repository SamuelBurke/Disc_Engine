#include "Input.h"

#include <iostream>

using namespace Disc_Engine;


//void Input::Init()
//{
//}

void Input::MouseUpdate()
{
	SDL_PumpEvents();

	SDL_GetMouseState(&m_mouseX, &m_mouseY);

	//std::cout << "MouseX: " << m_mouseX << std::endl;
	//std::cout << "MouseY: " << m_mouseY << std::endl;
}

bool Input::GetKey(int _keyCode)
{
	//if (_keyCode == 1)
	//{
	//	std::cout << "true" << std::endl;
	//	return true;
	//}


	for (size_t i = 0; i < m_keyCodes.size(); i++)
	{
		if (_keyCode == m_keyCodes.at(i))
		{
			return m_keyCodes.at(i);
			break;
		}
	}
}

bool Input::GetKeyUp(int _keyCode)
{
	//SAME AS ABOVE::CHANGE LATER
	for (size_t i = 0; i < m_keyCodes.size(); i++)
	{
		if (_keyCode == m_keyCodes.at(i))
		{
			return m_keyCodes.at(i);
			break;
		}
	}
}

bool Input::GetKeyDown(int _keyCode)
{
	//SAME AS ABOVE::CHANGE LATER
	for (size_t i = 0; i < m_keyCodes.size(); i++)
	{
		if (_keyCode == m_keyCodes.at(i))
		{
			return m_keyCodes.at(i);
			break;
		}
	}
}
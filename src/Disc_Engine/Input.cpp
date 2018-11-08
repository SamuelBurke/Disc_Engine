#include "Input.h"

using namespace Disc_Engine;

bool Input::GetKey(int _keyCode)
{
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
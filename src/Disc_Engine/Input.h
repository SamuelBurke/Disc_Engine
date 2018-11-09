#ifndef DISC_ENGINE_INPUT_H
#define DISC_ENGINE_INPUT_H

#include <vector>

#include <SDL2/SDL.h>

namespace Disc_Engine
{
class Input
{
public:
	//void Init();
	void MouseUpdate();

	bool GetKey(int _keyCode);
	bool GetKeyUp(int _keyCode);
	bool GetKeyDown(int _keyCode);

private:
	std::vector<int> m_keyCodes;

	int m_mouseX;
	int m_mouseY;
};
}

#endif // !DISC_ENGINE_INPUT_H

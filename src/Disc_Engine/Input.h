#ifndef DISC_ENGINE_INPUT_H
#define DISC_ENGINE_INPUT_H

#include <SDL2/SDL.h>

#include <memory>

namespace Disc_Engine
{
class Input
{
public:
	void Init();
	void Update();

	bool isKeyPressed(SDL_Scancode _keyCode); //returns true when key is pressed


private:
	int m_mouseX;
	int m_mouseY;

	const Uint8* m_currentKey;

};
}

#endif // !DISC_ENGINE_INPUT_H

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
	void End();

	bool isKeyPressed(SDL_Scancode _keyCode); //returns true when key is pressed
	bool isKeyHeld(SDL_Scancode _keyCode); //continuously returns true when the key is held
	bool isKeyReleased(SDL_Scancode _keyCode); //returns true when the key is released



private:
	int m_keys;

	int m_mouseX;
	int m_mouseY;

	const Uint8* m_currentKey;
	Uint8* m_currentKeys;
	Uint8* m_previousKeys;

};
}

#endif // !DISC_ENGINE_INPUT_H

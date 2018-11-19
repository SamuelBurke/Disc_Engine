#ifndef DISC_ENGINE_INPUT_H
#define DISC_ENGINE_INPUT_H

#include "Window.h"

#include <SDL2/SDL.h>

#include <memory>
#include <glm/glm.hpp>

namespace Disc_Engine
{
class Input
{
public:
	void Init();
	void Update();

	bool isKeyPressed(SDL_Scancode _keyCode); //returns true when key is pressed

	//bool isMouseMoving();
	//glm::vec3 GetMouseRotAngle();
	//glm::vec2 GetMousePosition();
	//void SetPrevMousePos(glm::vec2 _mousePos);

private:
	//int m_mouseX = 0;
	//int m_mouseY = 0;

	//int m_prevMouseX = 0;
	//int m_prevMouseY = 0;

	const Uint8* m_currentKey;

	//sWindow m_window;

};
}

#endif // !DISC_ENGINE_INPUT_H

#ifndef DISC_ENGINE_WINDOW_H
#define DISC_ENGINE_WINDOW_H

#include <SDL2/SDL.h>

namespace Disc_Engine
{

class Window
{
public:
	void InitWin();
	void ClearBuff();
	void SwapWin();

	static int GetWidth();
	static int GetHeight();

private:
	bool InitGL();

	static int m_width;
	static int m_height;

	SDL_Window* m_window;

};

}
#endif // !DISC_ENGINE_WINDOW_H

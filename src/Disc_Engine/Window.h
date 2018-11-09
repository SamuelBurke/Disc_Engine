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


	//unsigned int GetWid() { return m_wid; }
	//unsigned int GetHei() { return m_hei; }

private:
	bool InitGL();

	unsigned int m_wid, m_hei;

	SDL_Window* m_window;

};

}
#endif // !DISC_ENGINE_WINDOW_H

#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

class Window
{
public:
	void InitWin();
	void ClearBuff();
	void SwapWin();

	//unsigned int GetWid() { return m_wid; }
	//unsigned int GetHei() { return m_hei; }

private:
	unsigned int m_wid, m_hei;

	SDL_Window* m_window;

};

#endif // !WINDOW_H

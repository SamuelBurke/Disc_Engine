#include "Window.h"

#include <GL/glew.h>

#include <exception>
#include <iostream>

using namespace Disc_Engine;

//constexpr auto WINDOW_WIDTH = 800;
//constexpr auto WINDOW_HEIGHT = 600;
int WINDOW_WIDTH = 800;
int WINDOW_HEIGHT = 600;

void Window::InitWin()
{

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw std::exception();
	}

	m_window = SDL_CreateWindow("Disc Engine",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	if (!SDL_GL_CreateContext(m_window))
	{
		throw std::exception();
	}

	if (glewInit() != GLEW_OK)
	{
		throw std::exception();
	}

	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
}

void Window::ClearBuff()
{
	SDL_GetWindowSize(m_window, &WINDOW_WIDTH, &WINDOW_HEIGHT);
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//std::cout << "Buffer Cleared Successfully" << std::endl;
}

void Window::SwapWin()
{
	SDL_GL_SwapWindow(m_window);

	//std::cout << "Window Swapped Successfully" << std::endl;
}
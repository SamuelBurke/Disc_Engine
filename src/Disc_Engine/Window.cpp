#include "Window.h"

#include <GL/glew.h>

#include <exception>
#include <iostream>
#include <string>

using namespace Disc_Engine;

int Window::m_width = 800;
int Window::m_height = 600;

bool Window::InitGL()
{
	glewExperimental = GL_TRUE;

	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		//glewInit() failed.
		std::cerr << "Error: GLEW failed to initalise: " << glewGetErrorString(err) << std::endl;
		return false;
	}

	std::cout << "[INFO]: Using GLEW " << glewGetString(GLEW_VERSION) << std::endl;

	std::cout << "[INFO]: OpenGL Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "[INFO]: OpenGL Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "[INFO]: OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "[INFO]: OpenGL Shading Language Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

	return true;
}

void Window::InitWin()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Error: Cannot initialise SDL" << std::endl;

		throw std::exception();
	}

	//Major version number 4
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	//Minor version number 3
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	m_window = SDL_CreateWindow("Disc Engine",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		m_width, m_height,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	if (!SDL_GL_CreateContext(m_window))
	{
		throw std::exception();
	}

	if (!InitGL())
	{
		throw std::exception();
	}

	//SDL_SetRelativeMouseMode(SDL_TRUE);

	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
}

void Window::ClearBuff()
{
	SDL_GetWindowSize(m_window, &m_width, &m_height);
	glViewport(0, 0, m_width, m_height);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//std::cout << "Buffer Cleared Successfully" << std::endl;
}

void Window::SwapWin()
{
	SDL_GL_SwapWindow(m_window);

	//std::cout << "Window Swapped Successfully" << std::endl;
}

int Window::GetWidth()
{
	return m_width;
}

int Window::GetHeight()
{
	return m_height;
}
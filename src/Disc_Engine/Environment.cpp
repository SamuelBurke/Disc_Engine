#include "Environment.h"

#include <iostream>
#include <SDL2/SDL.h>

using namespace Disc_Engine;

void Environment::Init()
{
	m_lastTime = SDL_GetTicks();
}

float Environment::CalculateDeltaTime()
{
	float time = SDL_GetTicks();
	float difference = time - m_lastTime;
	m_deltaTime = difference / 1000.0f;
	m_lastTime = time;


	//float idealTime = 1.0f / 60.0f;

	//if (idealTime < m_deltaTime)
	//{
	//	//sleep off remaining time
	//	SDL_Delay((idealTime - m_deltaTime) * 1000.0f);
	//}

	






	return m_deltaTime;
}
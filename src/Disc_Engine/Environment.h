#ifndef DISC_ENGINE_ENVIRONMENT_H
#define DISC_ENGINE_ENVIRONMENT_H

namespace Disc_Engine
{

class Environment
{
public:
	void Init();
	float CalculateDeltaTime();

private:
	float m_deltaTime = 0;
	float m_lastTime;
	
};

}



#endif // !DISC_ENGINE_ENVIRONMENT_H

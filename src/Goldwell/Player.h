#ifndef PLAYER_H
#define PLAYER_H

#include "Disc_Engine/Component.h"
#include "Disc_Engine/Transform.h"

class Transform;

class Player : public Disc_Engine::Component
{
public:
	void OnInit();

private:
	void OnTick(float _deltaTime);
	void OnDisplay();

	float m_angle;
};

#endif // !PLAYER_H

#ifndef DISC_ENGINE_MESHRENDERER_H
#define DISC_ENGINE_MESHRENDERER_H

#include "Component.h"

#include <memory>

namespace Disc_Engine
{
class Shader;

class MeshRenderer : public Component
{
public:
	void OnInit();

private:
	void OnTick(float _deltaTime);
	void OnDisplay();

	float m_angle;

	std::shared_ptr<Shader> m_shader;
	
};

}

#endif // !DISC_ENGINE_MESHRENDERER_H
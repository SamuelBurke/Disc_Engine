#ifndef DISC_ENGINE_MESHRENDERER_H
#define DISC_ENGINE_MESHRENDERER_H

#include "Component.h"

#include <memory>

namespace Disc_Engine
{
class Shader;
class VertexArray;
class Texture;

class MeshRenderer : public Component
{
public:
	void OnInit();
	void OnTick();

private:
	void OnDisplay();

	std::shared_ptr<VertexArray> m_debugCube;
	std::shared_ptr<Texture> m_cubeTexture;

	std::shared_ptr<Shader> m_shader;

	float m_angle;

};
}

#endif // !DISC_ENGINE_MESHRENDERER_H
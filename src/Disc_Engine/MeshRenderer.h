#ifndef DISC_ENGINE_MESHRENDERER_H
#define DISC_ENGINE_MESHRENDERER_H

#include "Component.h"

#include <memory>

namespace Disc_Engine
{
class Shader;
class VertexArray;

class MeshRenderer : public Component
{
public:
	void OnInit();
	//void OnTick() override;

private:
	void OnDisplay();

	//GLuint m_positionsVboId, m_vaoId;
	//GLuint m_programId;

	std::shared_ptr<VertexArray> m_shape;
	std::shared_ptr<Shader> m_shader;

};
}

#endif // !DISC_ENGINE_MESHRENDERER_H
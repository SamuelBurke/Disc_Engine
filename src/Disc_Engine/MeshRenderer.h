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

	//GLuint m_positionsVboId, m_vaoId;
	//GLuint m_programId;

	//std::shared_ptr<VertexArray> m_shape;
	std::shared_ptr<VertexArray> m_cat;
	std::shared_ptr<VertexArray> m_hall;

	std::shared_ptr<Texture> m_catTex;
	std::shared_ptr<Texture> m_hallTex;

	std::shared_ptr<Shader> m_shader;
	//std::shared_ptr<Texture> m_texture;

	float m_angle;

};
}

#endif // !DISC_ENGINE_MESHRENDERER_H
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

	void SetMesh(std::weak_ptr<VertexArray> _mesh);
	std::shared_ptr<VertexArray> GetMesh();

	void SetMaterial(std::weak_ptr<Texture> _texture);
	std::shared_ptr<Texture> GetMaterial();

private:
	void OnTick(float _deltaTime);
	void OnDisplay();

	float m_angle;

	std::shared_ptr<Shader> m_shader;
	std::weak_ptr<VertexArray> m_currentMesh;
	std::weak_ptr<Texture> m_currentTexture;	
};

}

#endif // !DISC_ENGINE_MESHRENDERER_H
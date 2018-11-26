#ifndef DISC_ENGINE_MESHRENDERER_H
#define DISC_ENGINE_MESHRENDERER_H

#include "Component.h"

#include <memory>

namespace Disc_Engine
{
class Shader;
class VertexArray;
class Texture;

class MeshRenderer : public Component // Inherits from Component, attached to anything that needs to be displayed (Player, Fruit).
{
public:
	void OnInit();

	void SetMesh(std::weak_ptr<VertexArray> _mesh); // Sets the current mesh.
	std::shared_ptr<VertexArray> GetMesh();

	void SetMaterial(std::weak_ptr<Texture> _texture); // Sets the current texture.
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
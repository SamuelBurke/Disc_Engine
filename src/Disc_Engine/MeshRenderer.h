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
	void OnTick(float _deltaTime);

private:
	void OnDisplay();

	std::shared_ptr<VertexArray> m_debugCube;
	std::shared_ptr<Texture> m_cubeTexture;

	std::shared_ptr<VertexArray> m_wall;
	std::shared_ptr<Texture> m_wallTexture;

	std::shared_ptr<Shader> m_shader;

	float m_angle;



	glm::mat4 m_cube;
	glm::vec3 m_cubePos;

	glm::vec3 m_secondCubePos;
	glm::mat4 m_secondCube;



};
}

#endif // !DISC_ENGINE_MESHRENDERER_H
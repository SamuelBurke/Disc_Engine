#ifndef DISC_ENGINE_MESHRENDERER_H
#define DISC_ENGINE_MESHRENDERER_H

#include "Component.h"
#include "Shader.h"
//#include "Mesh.h"

#include <memory>
#include <GL/glew.h>

namespace Disc_Engine
{
class MeshRenderer : public Component
{
public:
	void Init();

	void SetUp();
	void Draw();

private:
	void Display();

	GLuint m_positionsVboId, m_vaoId;
	GLuint m_programId;

	std::shared_ptr<Shader> m_shader;

};
}

#endif // !DISC_ENGINE_MESHRENDERER_H
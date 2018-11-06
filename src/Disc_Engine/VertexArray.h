#ifndef DISC_ENGINE_VERTEXARRAY_H
#define DISC_ENGINE_VERTEXARRAY_H

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <vector>
#include <string>
#include <memory>

namespace Disc_Engine
{
class VertexBuffer;

class VertexArray
{
public:
	VertexArray();
	void SetBuffer(std::string _attribute, std::weak_ptr<VertexBuffer> _buffer);
	int GetVertexCount();
	GLuint GetID();

private:
	GLuint m_id;
	bool m_dirty;
	std::vector <std::shared_ptr<VertexBuffer>> m_buffers;
};

}

#endif // !DISC_ENGINE_VERTEXARRAY_H
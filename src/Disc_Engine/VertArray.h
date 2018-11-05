#ifndef DISC_ENGINE_VERTARRAY_H
#define DISC_ENGINE_VERTARRAY_H

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <vector>
#include <string>
#include <memory>

namespace Disc_Engine
{
class VertBuffer;

class VertArray
{
public:
	VertArray();
	void SetBuffer(std::string _attribute, std::weak_ptr<VertBuffer> _buffer);
	int GetVertexCount();
	GLuint GetID();

private:
	GLuint m_id;
	bool m_dirty;
	std::vector <std::shared_ptr<VertBuffer>> m_buffers;
};

}

#endif // !DISC_ENGINE_VERTARRAY_H
#ifndef DISC_ENGINE_MESHRENDERER_H
#define DISC_ENGINE_MESHRENDERER_H

#include "Component.h"

namespace Disc_Engine
{
class MeshRenderer : public Component
{
public:
	void Init();

private:
	void Display();
};
}

#endif // !DISC_ENGINE_MESHRENDERER_H
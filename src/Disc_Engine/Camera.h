#ifndef DISC_ENGINE_CAMERA_H
#define DISC_ENGINE_CAMERA_H

#include "Component.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>

namespace Disc_Engine
{

class Camera : public Component
{
public:
	void OnInit();
	void OnTick();

private:
	void OnDisplay();


	glm::mat4 m_viewMatrix;
	glm::mat4 m_projMatrix;

	glm::quat m_cameraOrientation;
};

}

#endif // !DISC_ENGINE_CAMERA_H

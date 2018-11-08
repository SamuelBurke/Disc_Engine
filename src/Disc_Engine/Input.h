#ifndef DISC_ENGINE_INPUT_H
#define DISC_ENGINE_INPUT_H

#include <vector>

namespace Disc_Engine
{
class Input
{
public:
	bool GetKey(int _keyCode);
	bool GetKeyUp(int _keyCode);
	bool GetKeyDown(int _keyCode);

private:
	std::vector<int> m_keyCodes;
};
}

#endif // !DISC_ENGINE_INPUT_H

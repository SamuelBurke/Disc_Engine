#ifndef DISC_ENGINE_RESOURCESHANDLER_H
#define DISC_ENGINE_RESOURCESHANDLER_H

#include "Resource.h"

#include <iostream>
#include <memory>
#include <vector>

namespace Disc_Engine
{

class ResourcesHandler
{
public:

	//template <typename T> 
	//std::shared_ptr<T> Create();

	template <typename T>
	std::shared_ptr<T> Load(std::string _filePath);

	//template <typename T>
	//std::shared_ptr<T> GetResource();


private:
	std::vector<std::shared_ptr<Resource>> m_resources;
};

template<typename T>
inline std::shared_ptr<T> ResourcesHandler::Load(std::string _filePath)
{
	for (size_t i = 0; i < m_resources.size(); i++)
	{
		//TODO:::SET FILE PATH SO THIS GETS CALLED
		if (m_resources.at(i)->GetFilePath() == _filePath)
		{
			std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(m_resources.at(i));
				
			//

			return rtn;
		}
	}
	std::shared_ptr<T> rtn = std::make_shared<T>();
	rtn->Load(_filePath);

	m_resources.push_back(rtn);

	return rtn;
}
}
#endif // !DISC_ENGINE_RESOURCESHANDLER_H

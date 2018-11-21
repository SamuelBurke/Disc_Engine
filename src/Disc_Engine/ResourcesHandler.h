#ifndef DISC_ENGINE_RESOURCESHANDLER_H
#define DISC_ENGINE_RESOURCESHANDLER_H

#include "Resource.h"

#include <iostream>
#include <memory>
#include <list>

namespace Disc_Engine
{

class ResourcesHandler
{
public:
	template <typename T>
	std::shared_ptr<T> CreateResource();

	template <typename T>
	std::shared_ptr<T> GetResource();


private:
	std::list<std::shared_ptr<Resource>> m_resources;
};


template <typename T>
inline std::shared_ptr<T> ResourcesHandler::CreateResource()
{
	std::shared_ptr<T> rtn = std::make_shared<T>();
	m_resources.push_back(rtn);

	return rtn;
}


template<typename T>
inline std::shared_ptr<T> ResourcesHandler::GetResource()
{
	for (size_t i = 0; i < m_resources.size(); i++)
	{
		std::shared_ptr<T> currentResource = std::dynamic_pointer_cast<T>(m_resources.get_allocator(i));

		if (m_resources)
		{
			return m_resources;
		}
	}


	std::cout << typeid(T).name() << std::endl;
	return nullptr;
	throw std::exception();
	
}

}
#endif // !DISC_ENGINE_RESOURCESHANDLER_H

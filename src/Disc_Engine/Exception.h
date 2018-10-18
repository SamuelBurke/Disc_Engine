#ifndef DISC_ENGINE_EXCEPTION_H
#define DISC_ENGINE_EXCEPTION_H

#include <exception>
#include <string>

namespace Disc_Engine
{
class Exception : public std::exception
{
public:
	Exception(std::string _message);
	~Exception() throw();

	const char *what();

private:
	std::string m_message;
};

}

#endif // !DISC_ENGINE_EXCEPTION_H

#include "Exception.h"

using namespace Disc_Engine;

Exception::Exception(std::string _message)
{
	m_message = _message;
}

Exception::~Exception() throw()
{

}

const char* Exception::what()
{
	return "Exception test";
}
#include "stdafx.h"
#include "LLException.h"

CLLException::CLLException(const char * str) :
	std::runtime_error(str)
{
}

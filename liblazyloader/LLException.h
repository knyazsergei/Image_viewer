#pragma once
#include <stdexcept>

class CLLException :
	public std::runtime_error
{
public:
	CLLException(const char * str);
	~CLLException() = default;
};


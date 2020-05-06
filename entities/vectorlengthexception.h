#pragma once
#include <exception>

class VectorLengthException : public std::exception {
public:
	virtual const char* what() const throw()
	{
		return "Vector length can't be 0! \n";
	}
};
#ifndef _EQUAL_POINTS_EXCEPTION__
#define _EQUAL_POINTS_EXCEPTION__
#include <iostream>
using namespace std;

class EqualPointException : public exception
{
    const char *msg;

public:
    EqualPointException(const char *msg)
    {
        this->msg = msg;
    }

    virtual const char *what() const throw()
    {
        return msg;
    }
};

#endif
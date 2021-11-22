#include "RocketCaretaker.h"

RocketCaretaker::RocketCaretaker() 
{
    _mem = nullptr;
}

RocketCaretaker::~RocketCaretaker() 
{
    if (_mem != nullptr)
	{
		delete _mem;
	}
}

void RocketCaretaker::setMemento(RocketMemento* m)
{
    _mem = m;
}

RocketMemento* RocketCaretaker::getMemento()
{
    return _mem;
}
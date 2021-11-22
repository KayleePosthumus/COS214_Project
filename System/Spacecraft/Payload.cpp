#include "Payload.h"

Payload::Payload(string name)
{ 
    _name = name;
}

Payload::~Payload()
{
}

Payload* Payload::GetNext()
{
    return _next;
}

void Payload::SetNext(Payload *next)
{
	_next = next;
}

string Payload::GetName()
{
    return _name;
}
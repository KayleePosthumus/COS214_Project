#include "Human.h"

Human::Human(std::string n) 
{
    _name = n;
}

Human::~Human()
{
    
}

void Human::SetName(std::string n)
{
    _name = n;
}

std::string Human::GetName()
{
    return _name;
}

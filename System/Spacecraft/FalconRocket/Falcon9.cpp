#include "Falcon9.h"

using namespace std;

Falcon9::Falcon9(string name) : Rocket(name)
{
}

Falcon9::~Falcon9()
{
}

Stage* Falcon9::getStage() 
{
    return this->subjectStage;
}

void Falcon9::setStage(Stage* stage) 
{
    this->subjectStage = stage;
}

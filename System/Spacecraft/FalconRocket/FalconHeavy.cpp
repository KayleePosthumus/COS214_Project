#include "FalconHeavy.h"

using namespace std;

FalconHeavy::FalconHeavy(string name) : Rocket(name)
{
}

FalconHeavy::~FalconHeavy()
{
}

Stage* FalconHeavy::getStage() 
{
    return this->subjectStage;
}

void FalconHeavy::setStage(Stage* stage) 
{
    this->subjectStage = stage;
}

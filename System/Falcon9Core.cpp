#include "Falcon9Core.h"

using namespace std;

Falcon9Core::Falcon9Core(string name) : Core(name)
{
    this->SetHealth(Falcon9CoreConfig::health);
}
Falcon9Core::~Falcon9Core() {}

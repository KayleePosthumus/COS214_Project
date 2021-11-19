#include "Rocket.h"

using namespace std;

Rocket::Rocket(string name)
{
    this->name = name;
}
Rocket::~Rocket()
{
}

void Rocket::SetComponents(Component *components)
{
    this->components = components;
}
void Rocket::AddComponents(Component *components)
{
    Component *tail = components;
    while (components->successor)
    {
        components = components->successor;
    }
    components->successor = this->components;
    this->components = tail;
}
void Rocket::SetPayload(vector<Payload *> *payload)
{
    this->payload = payload;
}

void Rocket::TakeLiftOffDamage()
{
    if (this->components)
        this->components->TakeLiftOffDamage(RNG::RandomDamageToComponents());
}
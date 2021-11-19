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

/*void Rocket::SetPayload(Payload *p)
{
    this->payload = p;
}*/

void Rocket::TakeLiftOffDamage()
{
    if (this->components)
        this->components->TakeLiftOffDamage(RNG::RandomDamageToComponents());
}

void Rocket::attach(Observer* o) 
{
    this->observerList.push_back(o);
}

void Rocket::detach(Observer* o) 
{
    for(vector<Observer*>::iterator it = observerList.begin(); it != observerList.end(); ++it)
    {
        if(*(it) == o)
            observerList.erase(it);
    }
    
}
void Rocket::notify() 
{
    for(vector<Observer*>::iterator it = observerList.begin(); it != observerList.end(); ++it)
    {
        (*it)->update();
    }
}

Stage* Rocket::getStage() 
{
    return this->subjectStage;
}

void Rocket::setStage(Stage* stage) 
{
    this->subjectStage = stage;
}
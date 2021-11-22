#include "Rocket.h"

#include <iostream>

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

void Rocket::TransitionIntoStageTwo(Component *prev)
{
    cout << "Transitioning into stage 2" << endl;
    if (this->components && this->components->successor)
        this->components->successor->TransitionIntoStageTwo(this->components);
}
void Rocket::attach(Observer *o)
{
    this->observerList.push_back(o);
}

void Rocket::detach(Observer *o)
{
    for (vector<Observer *>::iterator it = observerList.begin(); it != observerList.end(); ++it)
    {
        if (*(it) == o)
            observerList.erase(it);
    }
}
void Rocket::notify()
{
    for (vector<Observer *>::iterator it = observerList.begin(); it != observerList.end(); ++it)
    {
        (*it)->update();
    }
}

Stage *Rocket::getStage()
{
    return this->subjectStage;
}

void Rocket::setStage(Stage *stage)
{
    this->subjectStage = stage;
}

void Rocket::restoreMemento(RocketMemento *mem)
{
    RocketState *s = mem->getState();

    // might be needed, commented out in case
    //delete this->components;
    //delete this->subjectStage;

    this->name = s->GetName();
    this->health = s->GetHealth();
    this->components = s->GetComponents()->Clone();
    this->subjectStage = s->GetStage()->Clone();
}

RocketMemento *Rocket::createMemento()
{
    return new RocketMemento(this->name, this->health, this->components, this->subjectStage);
}

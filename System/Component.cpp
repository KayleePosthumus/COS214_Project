#include "Component.h"

#include <iostream>

using namespace std;

Component::Component(string name)
{
    this->name = name;
}
Component::Component(string name, Component *successor)
{
    this->name = name;
    this->successor = successor;
}

Component::~Component() {}

void Component::TakeDamage(int damageAmount)
{
    if (this->health <= 1)
    {
        return;
    }

    this->health -= damageAmount;

    if (this->health <= 1)
    {
        cout << this->name << " was destroyed." << endl;
        this->Destroy();
    }
}

int Component::GetHealth()
{
    return this->health;
}
void Component::SetHealth(int health)
{
    this->health = health;
}

string Component::GetName()
{
    return this->name;
}
void Component::SetName(string name)
{
    this->name = name;
}
#include "Component.h"

#include <iostream>

using namespace std;

Component::Component(string name)
{
    this->name = name;
}
Component::~Component() {}

void Component::TakeDamage(int damageAmount)
{
    this->health -= damageAmount;

    if (this->health <= 1)
    {
        cout << this->name << " was destroyed." << endl;
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
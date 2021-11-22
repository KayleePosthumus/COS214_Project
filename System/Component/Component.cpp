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

Component::~Component()
{
}

bool Component::TakeDamage(int damageAmount)
{
    if(this->health <= 0)
    {
        return false;
    }

    float percentage = ((float) health - (float) damageAmount) / (float) health * 100;
    this->health -= damageAmount;
    cout << this->name << " sustained " << damageAmount << " units of damage." << endl;

    if(this->health <= 0)
    {
        cout << this->name << " was destroyed." << endl;
        this->Destroy();
        return false;
    }
    else
    {
        if(percentage >= 0)
            cout << name << " is at " << percentage << "% health" << endl;
        else
            cout << name << " is at 0% health" << endl;
            
        return true;
    }
}

void Component::TakeLiftOffDamage(int damageAmount)
{
    this->TakeDamage(damageAmount);
    if (this->successor)
        this->successor->TakeLiftOffDamage(RNG::RandomDamageToComponents());
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
#include "RocketBuilder.h"

RocketBuilder::RocketBuilder()
{
}

RocketBuilder::~RocketBuilder()
{
}

Human* RocketBuilder::AddPeople()
{
    cout << "Please enter the passengers name: ";
    string name;
    cin >> name;

    return new Human(name);
}

Cargo* RocketBuilder::AddCargo()
{
    cout << "Please enter the cargo description: ";
    string des;
    cin >> des;

    cout << "Please enter the cargo weight: ";
    double weight;
    cin >> weight;

    return new Cargo(des, weight);
}

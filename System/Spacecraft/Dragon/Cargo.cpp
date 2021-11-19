#include "Cargo.h"

Cargo::Cargo(std::string d, double w)
{
    _description = d;
    _weight = w;
}

Cargo::~Cargo() {}

void Cargo::SetDescription(std::string d)
{
    _description = d;
}

void Cargo::SetWeight(double w)
{
    _weight = w;
}

std::string Cargo::GetDescription()
{
    return _description;
}

double Cargo::GetWeight()
{
    return _weight;
}

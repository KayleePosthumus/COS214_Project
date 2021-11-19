#ifndef CARGO_H
#define CARGO_H

#include <string>

class Cargo
{
private:
	std::string _description;
    double _weight;
public:
	Cargo(std::string, double);
	~Cargo();
	void SetDescription(std::string);
	void SetWeight(double);
    std::string GetDescription();
    double GetWeight();
};

#endif

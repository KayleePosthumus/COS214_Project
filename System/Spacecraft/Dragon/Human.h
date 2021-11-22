#ifndef HUMAN_H
#define HUMAN_H

#include <string>

class Human
{
private:
	std::string _name;
public:
	Human(std::string);
	~Human();
	void SetName(std::string);
	std::string GetName();
};

#endif

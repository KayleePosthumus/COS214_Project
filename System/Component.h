#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

using namespace std;

class Component
{
private:
	int health = 0;
	string name = "";

public:
	Component(string name);
	virtual ~Component();

	virtual void TakeDamage(int damageAmount);

	int GetHealth();
	void SetHealth(int health);

	string GetName();
	void SetName(string name);
};

#endif

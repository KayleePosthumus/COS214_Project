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
	Component(string name, Component *successor);
	virtual ~Component();

	virtual void TakeDamage(int damageAmount);
	virtual void Destroy() = 0;

	int GetHealth();
	void SetHealth(int health);

	string GetName();
	void SetName(string name);

	Component *successor; // for both the linked list and Chain of Command
};

#endif

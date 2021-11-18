#ifndef ENGINE_H
#define ENGINE_H

#include "Component.h"
#include "Settings.h"

#include <string>

using namespace std;

class Engine : public Component
{
private:
public:
	Engine(string name);
	~Engine();

	void Destroy();
};

#endif
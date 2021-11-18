#include "Core.h"

using namespace std;

Core::Core(string name) : Component(name) {}
Core::Core(string name, Component *successor) : Component(name, successor) {}

Core::~Core() {}

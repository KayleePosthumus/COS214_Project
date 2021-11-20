#ifndef ROCKETSTATE_H
#define ROCKETSTATE_H

#include "../Component/Component.h"
#include "../Stage/Stage.h"

#include <string>

using namespace std;

class RocketState
{
private:
    string _name;
    int _health;
    Component* _components;
    Stage* _subjectStage;

public:
    RocketState(string, int, Component*, Stage*);
    ~RocketState();

    int GetHealth();
    string GetName();
    Component* GetComponents();
    Stage* GetStage();
};

#endif
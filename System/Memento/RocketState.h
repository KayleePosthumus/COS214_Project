#ifndef ROCKETSTATE_H
#define ROCKETSTATE_H

#include "../Component/Component.h"
#include "../Stage/Stage.h"
#include "../Spacecraft/Payload.h"
#include "../Spacecraft/Observer.h"

#include <string>
#include <vector>

using namespace std;

class RocketState
{
private:
    string _name;
    int _rocketHealth;
    vector<int> _coreHealth;
    int _vacuumHealth;
    Stage* _subjectStage;

public:
    RocketState(string, int, vector<int>, int);
    ~RocketState();

    int GetHealth();
    string GetName();
    vector<int> GetCoreHealth();
    int GetVacuumHealth();
    Stage* GetStage();
};

#endif
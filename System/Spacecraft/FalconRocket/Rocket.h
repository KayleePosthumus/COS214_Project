#ifndef Rocket_H
#define Rocket_H

#include "../../Component/Component.h"
#include "../Payload.h"

#include <string>
#include <vector>

using namespace std;

class Rocket
{
private:
    string name;
    int health;

    Component *components; //linked list's tail
    vector<Payload *> *payload;

public:
    Rocket(string name);
    virtual ~Rocket();

    void SetComponents(Component *components);
    void AddComponents(Component *components);
    void SetPayload(vector<Payload *> *payload);

    void TakeLiftOffDamage();
};

#endif
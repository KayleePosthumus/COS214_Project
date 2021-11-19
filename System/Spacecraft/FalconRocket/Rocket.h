#ifndef Rocket_H
#define Rocket_H

#include "../../Component/Component.h"
#include "../Payload.h"
#include "../Observer.h"
#include "../../Stage/Stage.h"
#include "../SpaceCraft.h"

#include <string>
#include <vector>
class Observer;
using namespace std;

class Rocket : public SpaceCraft
{
private:
    string name;
    int health;

    Component *components; //linked list's tail
    vector<Payload *> *payload;
    //Payload* payload;
    vector<Observer*> observerList;

public:
    Rocket(string name);
    virtual ~Rocket();

    void SetComponents(Component *components);
    void AddComponents(Component *components);
    void SetPayload(vector<Payload *> *payload);
    //void SetPayload(Payload*);

    void TakeLiftOffDamage();

    void attach(Observer* o);
    void detach(Observer* o);
    void notify();    
};

#endif
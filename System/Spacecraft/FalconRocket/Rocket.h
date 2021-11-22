#ifndef Rocket_H
#define Rocket_H

#include "../../Component/Component.h"
#include "../Payload.h"
#include "../Observer.h"
#include "../../Stage/Stage.h"
#include "../../Memento/RocketMemento.h"
#include "../../Memento/RocketState.h"
#include "../../Settings.h"

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

class Observer;
class RocketMemento;
using namespace std;

class Rocket
{
private:
    string _name;
    int _health = 0;

    Component *_falcon9Cores = 0; //linked list's tail
    Component *_vacuumMerlin;
    Payload *_payload;
    vector<Observer*> _observerList;

protected:
    Stage* _subjectStage = 0;

public:
    Rocket(string name);
    virtual ~Rocket();

    void AddCores(Component *cores);
    void AddVacuum(Component *vacuum);
    void SetPayload(Payload *payload);

    virtual void TakeLiftOffDamage();

    string GetName();
    int GetHealth();
    void SetHealth(int h);
    string GetCores();
    Component* GetCoreList();
    int GetMerlinHealth();
    string GetPayloadName();
    Payload* GetPayload();

    void PrintDetails();
    virtual float GetHealthPercentage() = 0;

    void attach(Observer* o);
    void detach(Observer* o);
    void notify(); 

    void PrintStage();

    virtual bool GetState() = 0;

    Stage* getStage();
	void SetStage(Stage* stage);   
    
    void restoreMemento(RocketMemento*);
    RocketMemento* createMemento();
};

#endif
#include "Rocket.h"

using namespace std;

Rocket::Rocket(string name)
{
    _name = name;
}

Rocket::~Rocket()
{
    while(_falcon9Cores)
    {
        Component *current = _falcon9Cores;
        _falcon9Cores = _falcon9Cores->successor;
        delete current;
    }

    while(_payload)
    {
        Payload *current = _payload;
        _payload = _payload->GetNext();
        delete current;
    }

    delete _vacuumMerlin;
    
    if(_subjectStage)
        delete _subjectStage;
}

void Rocket::AddCores(Component *cores)
{
    if(!_falcon9Cores)
        _falcon9Cores = cores;
    else
    {
        Component* current = _falcon9Cores;
        while(current->successor)
        {
            current = current->successor;
        }

        current->successor = cores;
    }
}

void Rocket::AddVacuum(Component *vacuum)
{
    _vacuumMerlin = vacuum;
}

void Rocket::SetPayload(Payload *payload)
{
    _payload = payload;
}

void Rocket::TakeLiftOffDamage()
{
    if (_falcon9Cores)
    {
        int damage = RNG::RandomDamageToComponents();
        _falcon9Cores->TakeLiftOffDamage(damage);
    }
}

void Rocket::SetHealth(int h)
{
    _health = h;
}

string Rocket::GetName()
{
    return _name;
}

int Rocket::GetHealth()
{
    return _health;
}

string Rocket::GetCores()
{
    string out = "";

    Component* current = _falcon9Cores;
    while(current)
    {
        float percentage = ((float) current->GetHealth()) / (float) Falcon9CoreConfig::health * 100;

        if(percentage < 0)
        {
            out += current->GetName() + " : 0%\n";
        }
        else
        {
            out += current->GetName() + " : " + to_string(percentage) + "%\n";
        }

        current = current->successor;
    }
    
    return out;
}

Component* Rocket::GetCoreList()
{
    return _falcon9Cores;
}

int Rocket::GetMerlinHealth()
{
    return _vacuumMerlin->GetHealth();
}

string Rocket::GetPayloadName()
{
    string out = "";
    Payload* current = _payload;
    while(current)
    {
        if(current->GetNext())
            out += current->GetName() + ", ";
        else
            out += current->GetName() + "\n";

        current = current->GetNext();
    }

    return out;
}

Payload* Rocket::GetPayload()
{
    return _payload;
}

void Rocket::PrintDetails()
{
    float health = GetHealthPercentage();
	float merlinHealth = ((float) GetMerlinHealth()) / ((float) VacuumMerlinEngineConfig::health) * 100;

	cout << "\nName: " << GetName() << endl;
	cout << "Health: " << fixed << setprecision(2) << health << "%" <<  endl;
	cout << GetCores();
	cout << "Vacuum Merlin Health: " << fixed << setprecision(2) << merlinHealth << "%" <<  endl;
	cout << "Payload: " << GetPayloadName() << endl;
}

void Rocket::attach(Observer* o) 
{
    _observerList.push_back(o);
}

void Rocket::detach(Observer* o) 
{
    /*for(vector<Observer*>::iterator it = _observerList.begin(); it != _observerList.end(); ++it)
    {
        if(*(it) == o)
            _observerList.erase(it);
    }*/

    _observerList.pop_back();
}

void Rocket::notify() 
{
    for(vector<Observer*>::iterator it = _observerList.begin(); it != _observerList.end(); ++it)
    {
        (*it)->update();
    }
}

void Rocket::PrintStage()
{
    _subjectStage->handle();
}

Stage* Rocket::getStage() 
{
    return _subjectStage;
}

void Rocket::SetStage(Stage* stage) 
{
    if(_subjectStage)
        delete _subjectStage;
    _subjectStage = stage;
}

void Rocket::restoreMemento(RocketMemento* mem)
{
    RocketState* s = mem->getState();

    _name = s->GetName();
    _health = s->GetHealth();

    Component* current = _falcon9Cores;
    int i = 0;
    while(current)
    {
        current->SetHealth(s->GetCoreHealth()[i]);
        current = current->successor;
    }

    _vacuumMerlin->SetHealth(s->GetVacuumHealth());
}

RocketMemento* Rocket::createMemento()
{
    vector<int> coreHealth;
    Component* current = _falcon9Cores;
    while(current)
    {
        coreHealth.push_back(current->GetHealth());
        current = current->successor;
    }

    return new RocketMemento(_name, _health, coreHealth, _vacuumMerlin->GetHealth());
}
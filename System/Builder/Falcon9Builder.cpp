#include "Falcon9Builder.h"

using namespace std;

Falcon9Builder::Falcon9Builder()
{
}

Falcon9Builder::~Falcon9Builder()
{
}

void Falcon9Builder::ConstructRocket()
{
    _falcon9 = new Falcon9("Falcon 9 Rocket");
}

void Falcon9Builder::AddCoresAndMerlinEngines()
{
    Falcon9Core* falcon9Core = new Falcon9Core("Falcon 9 Core");
    Component* merlinEngine = new MerlinEngine("Merlin Engine");

    for(int i = 0; i < Falcon9Config::MerlinEnginesCount; ++i)
    {
        falcon9Core->AddEngines(merlinEngine);
    }

    _falcon9->AddCores(falcon9Core);
}

void Falcon9Builder::AddVacuumMerlinEngines()
{
    _falcon9->AddVacuum(new VacuumMerlinEngine("Vacuum Merlin Engine"));
}

void Falcon9Builder::AddPayload(RocketPayloadType PayloadType, int numberOfPayloadItems)
{
    if(PayloadType == RocketPayloadType::satellites)
    {
        Payload* satellites = new StarlinkSatellite("Satellite 1");
        Payload* current = satellites;
        for(int i = 2; i <= numberOfPayloadItems; ++i)
        {
            current->SetNext(new StarlinkSatellite("Satellite " + to_string(i)));
            current = current->GetNext();
        }

        _falcon9->SetPayload(satellites);
    }
    else if(PayloadType == RocketPayloadType::dragon)
    {
        DragonSpacecraft* dragon = new DragonSpacecraft("Dragon Spacecraft");
        
        int cargo = 1;
        while(cargo == 1)
        {
            dragon->AddCargo(RocketBuilder::AddCargo());

            cout << "\nWould you like to add more cargo:\n1.Yes\n2.No" << endl;
            cin >> cargo;
        }

        _falcon9->SetPayload(dragon);
    }
    else if(PayloadType == RocketPayloadType::crewDragon)
    {
        CrewDragon* crewDragon = new CrewDragon("Crew Dragon");
        int cargo = 1;
        while(cargo == 1)
        {
            crewDragon->AddCargo(RocketBuilder::AddCargo());

            cout << "\nWould you like to add more cargo:\n1.Yes\n2.No" << endl;
            cin >> cargo;
        }

        int human = 1;
        while(human == 1)
        {
            crewDragon->AddCrew(RocketBuilder::AddPeople());

            cout << "\nWould you like to add more people:\n1.Yes\n2.No" << endl;
            cin >> human;
        }

        _falcon9->SetPayload(crewDragon);
    }
}

Rocket *Falcon9Builder::GetRocket()
{
    return _falcon9;
}

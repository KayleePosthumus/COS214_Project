#include "FalconHeavyBuilder.h"

using namespace std;

FalconHeavyBuilder::FalconHeavyBuilder()
{
}

FalconHeavyBuilder::~FalconHeavyBuilder()
{
}

void FalconHeavyBuilder::ConstructRocket()
{
    _falconHeavy = new FalconHeavy("Falcon Heavy Rocket");
}

void FalconHeavyBuilder::AddCoresAndMerlinEngines()
{
    Falcon9Core* falcon9Core = new Falcon9Core("Falcon 9 Core");
    Component* merlinEngine = new MerlinEngine("Merlin Engine");

    for(int i = 0; i < Falcon9Config::MerlinEnginesCount; ++i)
    {
        falcon9Core->AddEngines(merlinEngine);
    }

    _falconHeavy->AddCores(falcon9Core);
    _falconHeavy->AddCores(falcon9Core->Clone());
    _falconHeavy->AddCores(falcon9Core->Clone());
}

void FalconHeavyBuilder::AddVacuumMerlinEngines()
{
    _falconHeavy->AddVacuum(new VacuumMerlinEngine("Vacuum Merlin Engine"));
}

void FalconHeavyBuilder::AddPayload(RocketPayloadType PayloadType, int numberOfPayloadItems)
{
    if(PayloadType == RocketPayloadType::dragon)
    {
        DragonSpacecraft* dragon = new DragonSpacecraft("Dragon Spacecraft");
        
        int cargo = 1;
        while(cargo == 1)
        {
            dragon->AddCargo(RocketBuilder::AddCargo());

            cout << "\nWould you like to add more cargo:\n1.Yes\n2.No" << endl;
            cin >> cargo;
        }

        _falconHeavy->SetPayload(dragon);
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

        _falconHeavy->SetPayload(crewDragon);
    }
}

Rocket *FalconHeavyBuilder::GetRocket()
{
    return _falconHeavy;
}

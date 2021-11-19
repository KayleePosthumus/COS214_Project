#include "Factory/CoreFactory.h"
#include "Factory/MerlinEngineFactory.h"
#include "Factory/VacuumMerlinEngineFactory.h"

#include "Builder/Falcon9Builder.h"
#include "Builder/FalconHeavyBuilder.h"

#include "StarlinkSatellite/Laser.h"
#include "StarlinkSatellite/StarlinkSatellite.h"

#include <iostream>

using namespace std;

int main()
{
    cout << "------------> Factory Design Patterns" << endl;
    cout << "------> Component Factory" << endl;
    cout << endl;

    cout << "---> Falcon9 Core Factory" << endl;
    ComponentFactory *falcon9CoreFactory = new CoreFactory();
    Component *falcon9Core = falcon9CoreFactory->produce();
    cout << "Name: " << falcon9Core->GetName() << endl;
    cout << "Health: " << falcon9Core->GetHealth() << endl;
    falcon9Core->TakeDamage(50);
    cout << "Health after taking damage: " << falcon9Core->GetHealth() << endl;
    cout << endl;

    cout << "---> Merlin Engine Factory" << endl;
    ComponentFactory *merlinEngineFactory = new MerlinEngineFactory();
    Component *merlinEngine = merlinEngineFactory->produce();
    cout << "Name: " << merlinEngine->GetName() << endl;
    cout << "Health: " << merlinEngine->GetHealth() << endl;
    merlinEngine->TakeDamage(50);
    cout << "Health after taking damage: " << merlinEngine->GetHealth() << endl;
    cout << endl;

    cout << "---> Vacuum Merlin Engine Factory" << endl;
    ComponentFactory *vacuumMerlinEngineFactory = new VacuumMerlinEngineFactory();
    Component *vacuumMerlinEngine = vacuumMerlinEngineFactory->produce();
    cout << "Name: " << vacuumMerlinEngine->GetName() << endl;
    cout << "Health: " << vacuumMerlinEngine->GetHealth() << endl;
    vacuumMerlinEngine->TakeDamage(50);
    cout << "Health after taking damage: " << vacuumMerlinEngine->GetHealth() << endl;
    cout << endl;

    cout << "------------> Builder Design Patterns" << endl;
    cout << "------> Falcon9 Builder" << endl;
    RocketBuilder *falcon9Builder = new Falcon9Builder();
    falcon9Builder->ConstructRocket();
    falcon9Builder->AddCoresAndMerlinEngines();
    falcon9Builder->AddVacuumMerlinEngines();
    Rocket *falcon9 = falcon9Builder->GetRocket();
    falcon9->TakeLiftOffDamage();
    cout << endl;

    cout << "------> FalconHeavy Builder" << endl;
    RocketBuilder *falconHeavyBuilder = new FalconHeavyBuilder();
    falconHeavyBuilder->ConstructRocket();
    falconHeavyBuilder->AddCoresAndMerlinEngines();
    falconHeavyBuilder->AddVacuumMerlinEngines();
    Rocket *falconHeavy = falconHeavyBuilder->GetRocket();
    falconHeavy->TakeLiftOffDamage();
    cout << endl;

	Laser* laser = new Laser();

	for (int i = 0; i < 60; i++) {
		laser->addSatellite(new StarlinkSatellite("SAT-"+ to_string(i)));
	}

	laser->notify();

	delete laser;

    return 0;
}
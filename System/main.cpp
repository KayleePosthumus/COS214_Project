#include "CoreFactory.h"
#include "MerlinEngineFactory.h"
#include "VacuumMerlinEngineFactory.h"

#include <iostream>

using namespace std;

int main()
{
    cout << "------------> Factory Design Patterns" << endl;
    cout << "------> Component Factory" << endl;
    cout << endl;

    cout << "---> Core Factory" << endl;
    ComponentFactory *coreFactory = new CoreFactory();
    Component *core = coreFactory->produce();
    cout << "Name: " << core->GetName() << endl;
    cout << "Health: " << core->GetHealth() << endl;
    core->TakeDamage(50);
    cout << "Health after taking damage: " << core->GetHealth() << endl;
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

    return 0;
}
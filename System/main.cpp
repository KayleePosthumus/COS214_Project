#include "CoreFactory.h"
#include "MerlinEngineFactory.h"

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

    return 0;
}
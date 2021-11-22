#include "TakeOff.h"

TakeOff::TakeOff(Rocket* rocket) : Command(rocket)
{

}

TakeOff::~TakeOff()
{

}

void TakeOff::Execute()
{
    _rocket->SetStage(new Stage1());
    _rocket->PrintStage();
    cout << "\nThe " << _rocket->GetName() << " has taken off!" << endl << endl;
    _rocket->TakeLiftOffDamage();
}

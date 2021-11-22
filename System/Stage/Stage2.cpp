#include "Stage2.h"
#include <iostream>

using namespace std;
Stage2::Stage2() {}
Stage2::~Stage2() {}

void Stage2::handle() 
{
    cout << "Rocket in stage 2" << endl;
}

Stage* Stage2::Clone()
{
    return new Stage2();
}
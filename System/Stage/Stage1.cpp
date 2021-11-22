#include "Stage1.h"
#include <iostream>
using namespace std;
Stage1::Stage1() {}
Stage1::~Stage1() {}

void Stage1::handle() 
{
    cout << "Rocket in stage 1" << endl;
}

Stage* Stage1::Clone()
{
    return new Stage1();
}
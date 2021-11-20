#include "Stage.h"

Stage::Stage() {}
Stage::~Stage() {}

void Stage::handle() 
{
    
}

Stage* Stage::Clone()
{
    return new Stage();
}
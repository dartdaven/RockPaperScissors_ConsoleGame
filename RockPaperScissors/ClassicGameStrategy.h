#pragma once
#include "GameStrategy.h"

class ClassicGameStrategy : public GameStrategy 
{
public:
	int determineWinner(int first, int second) override;
	int type() override;
};


#pragma once

#include "GameStrategy.h"

class BigBangGameStrategy : public GameStrategy
{
public:
	int determineWinner(int first, int second) override;
	int type() override;
};


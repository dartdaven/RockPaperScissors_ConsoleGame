#pragma once

#include "GameRules.h"

class BigBangGameRules : public GameRules
{
public:
	int determineWinner(Move first, Move second) override;
	Rules rules() override;
};


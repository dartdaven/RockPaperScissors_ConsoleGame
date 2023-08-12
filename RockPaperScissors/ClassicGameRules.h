#pragma once

#include "GameRules.h"

class ClassicGameRules : public GameRules 
{
public:
	int determineWinner(Move first, Move second) override;
	Rules rules() override;
};


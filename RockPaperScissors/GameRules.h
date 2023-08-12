#pragma once

#include "enumMove.h"
#include "enumRules.h"

class GameRules
{
public:
	virtual ~GameRules() {};
	virtual int determineWinner(Move first, Move second) = 0;
	virtual Rules rules() = 0;
};


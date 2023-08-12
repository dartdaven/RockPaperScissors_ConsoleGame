#pragma once

#include "enumMove.h"
#include "enumRules.h"

class Player
{
public:
	virtual ~Player() {};
	virtual Move MakeMove(const Rules& rules) = 0;
};


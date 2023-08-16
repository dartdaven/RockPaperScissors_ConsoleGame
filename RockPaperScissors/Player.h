#pragma once

#include <string>

#include "enumMove.h"
#include "enumRules.h"

class Player
{
public:
	Player() : score(0) {}
	virtual ~Player() {};
	virtual Move MakeMove(const Rules& rules) = 0;
	virtual std::string getName() = 0;
	
	int getScore();
	void resetScore();
	void incrementScore();

protected:
	int score;
};
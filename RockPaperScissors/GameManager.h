#pragma once

#include "BaseGameRules.h"
#include "BasePlayer.h"

class GameManager
{
public:
	void start();

private:
	int getWins4Victory();
};


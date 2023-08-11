#pragma once

#include "GameStrategy.h"


class Game
{
public:
	Game(GameStrategy* strategy) : strategy(strategy) {}
	
	int playRound(int first, int second);
	void start();


private:
	GameStrategy* strategy;
};


#pragma once

class GameStrategy
{
public:
	virtual ~GameStrategy() {};
	virtual int determineWinner(int first, int second) = 0;
	virtual int type() = 0;
};


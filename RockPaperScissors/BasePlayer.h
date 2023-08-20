#pragma once

#include <string>

#include "Enums.h"

class BasePlayer
{
public:
	BasePlayer() : score(0) {}
	virtual ~BasePlayer() {};

	virtual int makeMove(const int& possibleMovesAmount) const = 0;
	virtual std::string getName() const = 0;
	
	int getScore() const;
	void resetScore();
	void incrementScore();
	
	//for debug purposes only, need to delete
	void setScore(const int& number);

protected:
	int score;
};
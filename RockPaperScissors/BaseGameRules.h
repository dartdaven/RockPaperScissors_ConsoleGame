#pragma once

#include <string>
#include <vector>

#include "Enums.h"

class BaseGameRules
{
public:
	virtual ~BaseGameRules() {};
	virtual int determineWinner(const int& first, const int& second) const = 0;
	virtual Rules getRules() const = 0;
	virtual int getAmountOfMoves() const;
	virtual std::string stringOfPossibleMoves() const;
	virtual Move getMove(const int& integer) const;

protected:
	std::vector<Move> possibleMoves;
};


#pragma once

#include <string>
#include <vector>
#include <memory>

#include "../Misc/Enums.h"

enum class Rules { Classic, BigBang, Count };

class BaseGameRules
{
public:
	virtual ~BaseGameRules() {};

	//0 - Draw, 1 - First is the winner, 2 - Second is the winner 
	virtual int determineWinner(const std::pair<Move, Move>& pairOfMoves) const = 0;
	
	virtual Rules getRules() const = 0;
	const std::vector<Move>& getPossibleMoves() const { return possibleMoves; }

protected:
	std::vector<Move> possibleMoves;
};


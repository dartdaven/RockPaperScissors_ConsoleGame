#pragma once

#include "BaseGameRules.h"

class ClassicGameRules : public BaseGameRules 
{
public:
	ClassicGameRules();

	int determineWinner(const std::pair<Move, Move>& pairOfMoves) const override;
	Rules getRules() const override;
};


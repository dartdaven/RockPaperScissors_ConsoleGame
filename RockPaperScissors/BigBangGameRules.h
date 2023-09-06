#pragma once

#include "BaseGameRules.h"

class BigBangGameRules : public BaseGameRules
{
public:
	BigBangGameRules();

	int determineWinner(const std::pair<Move, Move>& pairOfMoves) const override;
	Rules getRules() const override;
};


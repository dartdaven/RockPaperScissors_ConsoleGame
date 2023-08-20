#pragma once

#include "BaseGameRules.h"

class BigBangGameRules : public BaseGameRules
{
public:
	BigBangGameRules();

	int determineWinner(const int& first, const int& second) const override;
	Rules getRules() const override;
};


#pragma once

#include "BaseGameRules.h"

class ClassicGameRules : public BaseGameRules 
{
public:
	ClassicGameRules();

	int determineWinner(const int& first, const int& second) const override;
	Rules getRules() const override;
};


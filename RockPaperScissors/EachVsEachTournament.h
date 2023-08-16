#pragma once

#include "Tournament.h"

class EachVsEachTournament : public Tournament
{
public:
	using Tournament::Tournament;
	void Play() override;
	void ShowRulesAndScore() override;
};


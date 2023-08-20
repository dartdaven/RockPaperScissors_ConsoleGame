#pragma once

#include "BaseTournament.h"

class EachVsEachTournament : public BaseTournament
{
public:
	using BaseTournament::BaseTournament;
	void Play() override;
	void ShowRulesAndScore() override;
};


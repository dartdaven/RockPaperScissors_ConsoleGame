#pragma once

#include "BaseTournament.h"
#include "EachVsEachTournamentUI.h"

class EachVsEachTournament : public BaseTournament
{
public:
	EachVsEachTournament(std::vector<std::shared_ptr<BasePlayer>>&& players, Rules rules, int wins4Victory = 1)
		: BaseTournament(std::move(players), rules, wins4Victory)
	{
		mName = "Each vs Each";
	}
	
	void Play() override;
};


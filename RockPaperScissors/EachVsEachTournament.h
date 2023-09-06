#pragma once

#include "BaseTournament.h"
#include "EachVsEachTournamentUI.h"

class EachVsEachTournament : public BaseTournament
{
public:
	//using BaseTournament::BaseTournament;
	EachVsEachTournament(std::vector<std::unique_ptr<BasePlayer>> players, std::unique_ptr<BaseGameRules> rules, const int& wins4Victory)
		: BaseTournament(std::move(players), std::move(rules), wins4Victory)
	{
		//UI = std::make_unique<EachVsEachTournamentUI>();
	}

	void Play() override;
};


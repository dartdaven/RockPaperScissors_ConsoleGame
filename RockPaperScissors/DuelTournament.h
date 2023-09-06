#pragma once

#include "BaseTournament.h"

class DuelTournament : public BaseTournament
{
public:
	//using BaseTournament::BaseTournament;
	DuelTournament(std::vector<std::unique_ptr<BasePlayer>> a_players, std::unique_ptr<BaseGameRules> rules, const int& wins4Victory = 1)
		: BaseTournament(std::move(a_players), std::move(rules), wins4Victory)
	{
		name = (players[1]->isBot()) ? "Single" : "Duel";
	}

	void Play() override;	
};
#pragma once

#include "BaseTournament.h"

class DuelTournament : public BaseTournament
{
public:
	//using BaseTournament::BaseTournament;
	DuelTournament(std::vector<std::shared_ptr<BasePlayer>>&& players, std::unique_ptr<BaseGameRules>&& rules, int wins4Victory = 1)
		: BaseTournament(std::move(players), std::move(rules), wins4Victory)
	{
		mName = (mPlayers[1]->isBot()) ? "Single" : "Duel";
	}

	void Play() override;	
};
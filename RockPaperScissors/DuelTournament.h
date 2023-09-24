#pragma once

#include "BaseTournament.h"

class DuelTournament : public BaseTournament
{
public:
	DuelTournament(std::vector<std::shared_ptr<BasePlayer>>&& players, Rules rules, int wins4Victory = 1)
		: BaseTournament(std::move(players), rules, wins4Victory)
	{
		mName = (mPlayers[1]->isBot()) ? "Single" : "Duel";
	}

	void Play() override;	
};
#pragma once

#include "BaseTournament.h"

class DuelTournament : public BaseTournament
{
public:
	DuelTournament(std::vector<std::shared_ptr<BasePlayer>>&& players, Rules rules, int wins4Victory = 1)
		: BaseTournament(std::move(players), rules, wins4Victory)
	{
		for (const auto& player : mPlayers)
		{
			if (player->isBot())
			{ 
				mName = "Single";
				return;
			}
		}
		mName = "Duel";
	}

	void Play() override;	
};
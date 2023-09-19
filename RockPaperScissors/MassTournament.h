#pragma once

#include "BaseTournament.h"

class MassTournament : public BaseTournament
{
public:
	MassTournament(std::vector<std::shared_ptr<BasePlayer>>&& players, std::unique_ptr<BaseGameRules>&& rules, int wins4Victory = 1)
		: BaseTournament(std::move(players), std::move(rules), wins4Victory)
	{
		mName = "Massive";
	}
	
	void Play() override;
	void PlayRound() override;
};
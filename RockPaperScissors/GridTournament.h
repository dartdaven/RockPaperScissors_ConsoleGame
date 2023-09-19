#pragma once

#include "BaseTournament.h"



class GridTournament : public BaseTournament
{
public:
	GridTournament(std::vector<std::shared_ptr<BasePlayer>>&& players, std::unique_ptr<BaseGameRules>&& rules, int wins4Victory = 1)
		: BaseTournament(std::move(players), std::move(rules), wins4Victory)
	{
		mName = (mPlayers.size() > 4) ? "Grid 8" : "Grid 4";
		mTours = (mPlayers.size() > 4) ? 3 : 2;
	}

	void Play() override;
private:
	int mTourCount{0};
	int mTours;
};


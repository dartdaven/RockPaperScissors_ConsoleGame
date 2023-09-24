#pragma once

#include "BaseTournament.h"



class GridTournament : public BaseTournament
{
public:
	GridTournament(std::vector<std::shared_ptr<BasePlayer>>&& players, Rules rules, int wins4Victory = 1)
		: BaseTournament(std::move(players), rules, wins4Victory)
	{
		mName = (mPlayers.size() > 4) ? "Grid 8" : "Grid 4";
		
		//hard code to fix
		mTours = (mPlayers.size() > 4) ? 3 : 2;
	}

	void Play() override;
private:
	int mTourCount{0};
	int mTours;
};


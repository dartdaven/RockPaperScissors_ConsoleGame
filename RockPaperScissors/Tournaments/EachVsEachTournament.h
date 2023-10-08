#pragma once

#include "BaseTournament.h"

#include <random>

class EachVsEachTournament : public BaseTournament
{
public:
	EachVsEachTournament(std::vector<std::shared_ptr<BasePlayer>>&& players, Rules rules, int wins4Victory = 1)
		: BaseTournament(std::move(players), rules, wins4Victory), mGen(mRd())
	{
		mName = "Each vs Each";
	}
	
	void Play() override;

private:
	std::random_device mRd;
	std::mt19937 mGen;
};


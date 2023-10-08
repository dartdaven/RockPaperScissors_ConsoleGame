#pragma once

#include <cmath>

#include "BaseTournament.h"

class GridTournament : public BaseTournament
{
public:
	GridTournament(std::vector<std::shared_ptr<BasePlayer>>&& players, Rules rules, int wins4Victory = 1);


	void Play() override;
	unsigned short getTourCount() const { return mTourCount; }

private:
	unsigned short mTourCount{0};
	unsigned short mTours;
};


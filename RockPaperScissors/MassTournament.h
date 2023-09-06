#pragma once

#include "BaseTournament.h"

class MassTournament : public BaseTournament
{
	using BaseTournament::BaseTournament;
	void Play() override;
	void PlayMassRound();
};


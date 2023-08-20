#pragma once

#include "BaseTournament.h"

class DuelTournament : public BaseTournament
{
public:
	using BaseTournament::BaseTournament;
	void Play() override;
	void ShowRulesAndScore() override;
};
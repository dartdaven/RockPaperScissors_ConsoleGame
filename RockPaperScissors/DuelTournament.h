#pragma once

#include "Tournament.h"

class DuelTournament : public Tournament
{
public:
	using Tournament::Tournament;
	void Play() override;
	void ShowRulesAndScore() override;
};
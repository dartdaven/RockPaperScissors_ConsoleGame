#pragma once

#include "Tournament.h"

class SingleTournament : public Tournament
{
public:
	using Tournament::Tournament;
	void Play() override;
	void ShowRulesAndScore() override;
};
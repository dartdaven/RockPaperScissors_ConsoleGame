#pragma once
#include "BaseTournamentUI.h"

class DuelTournamentUI :
    public BaseTournamentUI
{
	using BaseTournamentUI::BaseTournamentUI;

	//general funcs
	void showRules() const override;
	void showScore() const override;
};


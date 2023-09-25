#pragma once
#include "BaseTournamentUI.h"

class DuelTournamentUI :
    public BaseTournamentUI
{
	using BaseTournamentUI::BaseTournamentUI;

	//general funcs
	void showScore() const override;
};


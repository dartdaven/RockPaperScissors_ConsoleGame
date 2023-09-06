#pragma once
#include "BaseTournamentUI.h"

class DuelTournamentUI :
    public BaseTournamentUI
{
	using BaseTournamentUI::BaseTournamentUI;

	//general funcs
	void showRules() const override;
	void showScore() const override;

	//blank
	void onTournamentEvent(const Event& event) const override {};
};


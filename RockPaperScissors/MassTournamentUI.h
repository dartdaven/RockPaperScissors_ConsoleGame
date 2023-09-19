#pragma once
#include "BaseTournamentUI.h"
class MassTournamentUI :
    public BaseTournamentUI
{
	using BaseTournamentUI::BaseTournamentUI;

	virtual bool onEvent(const Event& event) const override;

	//general funcs
	void showRules() const override;
	void showScore() const override {};
};


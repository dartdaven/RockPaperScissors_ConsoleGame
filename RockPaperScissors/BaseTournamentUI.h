#pragma once

#include <iostream>

#include "BaseTournament.h"
#include "BaseGameRules.h"

class BasePlayer;

class BaseTournamentUI
{
public:
	BaseTournamentUI(std::unique_ptr<BaseTournament>& tournament) : tournament(tournament)
	{
		tournament->setRoundEventCallback(std::bind(&BaseTournamentUI::onRoundEvent, this, std::placeholders::_1));
		tournament->setTournamentEventCallback(std::bind(&BaseTournamentUI::onTournamentEvent, this, std::placeholders::_1));
	}
	virtual ~BaseTournamentUI() {};

	virtual void onRoundEvent(const Event& event) const;
	virtual void onTournamentEvent(const Event& event) const = 0;

	//general funcs
	virtual void showRules() const = 0;
	virtual void showScore() const = 0;

	std::string rulesToString(const Rules& rules) const;
	std::string moveToString(const Move& move) const;
	std::string stringOfPossibleMoves(const std::vector<Move>& possibleMoves) const;

	//not mine
	void winnerOfTheTournament(const std::string& name) const;

protected:
	std::unique_ptr<BaseTournament>& tournament;
};


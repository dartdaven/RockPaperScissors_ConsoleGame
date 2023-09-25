#pragma once

#include <iostream>

#include "BaseTournament.h"
#include "BaseGameRules.h"

class BasePlayer;

class BaseTournamentUI
{
public:
	BaseTournamentUI(std::shared_ptr<BaseTournament>& tournament) : tournament(tournament)
	{
		tournament->setEventCallback(std::bind(&BaseTournamentUI::onEvent, this, std::placeholders::_1));
	}
	virtual ~BaseTournamentUI() {};

	//true if the Event has been processed
	virtual bool onEvent(const Event& event) const;

	//general funcs
	virtual void showRules() const;
	virtual void showScore() const = 0;

	std::string stringOfPossibleMoves(const std::vector<Move>& possibleMoves) const;

	//not mine
	void winnerOfTheTournament(const std::string& name) const;

protected:
	std::weak_ptr<BaseTournament> tournament;
};


#pragma once

#include <memory>

#include "BaseTournamentUI.h"

class BaseTournament;

//To ask why
//class BaseTournamentUI;

class GameManager
{
public:
	void start();

private:
	int getWins4Victory();
	
	std::unique_ptr<BaseTournament> mTournament;
	std::unique_ptr<BaseTournamentUI> mUI;

	int mMaxPlayersNumber = 8;

};


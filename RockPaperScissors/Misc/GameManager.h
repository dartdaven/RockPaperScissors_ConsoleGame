#pragma once

#include <memory>

#include "../TournamentUIs/BaseTournamentUI.h"
class BaseTournament;

class GameManager
{
public:
	void start();

private:
	int getWins4Victory();
	void setupPlayers();
	
	std::shared_ptr<BaseTournament> mTournament;
	std::unique_ptr<BaseTournamentUI> mUI;
	std::vector<std::shared_ptr<BasePlayer>> mPlayersToMove;

	int mMaxPlayersNumber = 10;
	int mMaxPlayersNameSize = 8;

};


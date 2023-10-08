#include "GridTournament.h"

#include <iostream>
#include <Windows.h>
#include <memory>

#include "../Players/ComputerPlayer.h"

GridTournament::GridTournament(std::vector<std::shared_ptr<BasePlayer>>&& players, Rules rules, int wins4Victory)
	: BaseTournament(std::move(players), rules, wins4Victory)
{
	mName = "Grid " + std::to_string(static_cast<unsigned short>(std::pow(2, std::ceil(std::log2(mPlayers.size())))));
	mTours = static_cast<unsigned short>(ceil(log2(mPlayers.size())));
}

void GridTournament::Play()
{
	std::shared_ptr<ComputerPlayer> bot = std::make_unique<ComputerPlayer>();

	mEventCallback(Event::TournamentStarted);

	//Main cycle
	while (mPlayers.size() > 1 || mTourCount != mTours)
	{
		for (int i = 0; i < mPlayers.size(); i = i + 2)
		{
			if (i == mPlayers.size() - 1) {
				mPairOfCurrentRoundPlayers = { mPlayers[i], bot };
			}
			else {
				mPairOfCurrentRoundPlayers = { mPlayers[i], mPlayers[i + 1] };
			}
			PlayRound();
		}

		//Remove loosers
		++mTourCount;

		for (int i = static_cast<int>(mPlayers.size() - 1); i >= 0; --i)
		{
			if (mPlayers[i]->getScore() != mTourCount)
			{
				mPlayers.erase(mPlayers.begin() + i);
			}
		}
		
		mEventCallback(Event::MainCycleEnded);
	}

 	mEventCallback(Event::TournamentEnded);
}

#include "GridTournament.h"

#include <iostream>
#include <Windows.h>
#include <memory>

#include "ComputerPlayer.h"

void GridTournament::Play()
{
	std::shared_ptr<ComputerPlayer> bot = std::make_unique<ComputerPlayer>();
	
	while (mPlayers.size() > 1 || mTourCount != mTours)
	{
		for (int i = 0; i < mPlayers.size(); i = i + 2)
		{
			mEventCallback(Event::GridRoundStarted);

			if (i == mPlayers.size() - 1) {
				mPairOfRoundPlayers = { mPlayers[i], bot };
			}
			else {
				mPairOfRoundPlayers = { mPlayers[i], mPlayers[i + 1] };
			}
			PlayRound();

			mEventCallback(Event::GridRoundEnded);
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

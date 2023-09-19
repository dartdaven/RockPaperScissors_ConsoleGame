#include "MassTournament.h"

#include <iostream>
#include <set>
#include <vector>
#include <Windows.h>

#include "Enums.h"

void MassTournament::Play()
{
	while (true)
	{
		PlayRound();

		if (mPlayers.size() == 1) { break; }

		mEventCallback(Event::CantDetermineTheWinner);
	}

	mEventCallback(Event::TournamentEnded);
	return;
}

void MassTournament::PlayRound()
{
	while (true)
	{
		mEventCallback(Event::RoundStarted);
		mVectorofMassiveRoundMoves.clear();

		//Main cycle
		for (const auto& player : mPlayers)
		{
			mVectorofMassiveRoundMoves.push_back(player->makeMove(mRules));
			mEventCallback(Event::PlayerMadeMove);
		}

		mEventCallback(Event::MainCycleEnded);

		std::set<Move> tempUniqueMoves(mVectorofMassiveRoundMoves.begin(), mVectorofMassiveRoundMoves.end());
		if (tempUniqueMoves.size() == mRules->getPossibleMoves().size() || tempUniqueMoves.size() == 1)
		{
			mEventCallback(Event::CantDetermineLooser);
			continue;
		}

		std::vector<Move> uniqueMoves(tempUniqueMoves.begin(), tempUniqueMoves.end());

		//Check if there is a move that can beat someone and nobody beats him
		for (int i = 0; i < uniqueMoves.size() && uniqueMoves.size() != 1; ++i)
		{
			for (int j = 0; j < uniqueMoves.size(); ++j)
			{
				mPairOfRoundMoves = { uniqueMoves[i], uniqueMoves[j] };
				if (i == j) { continue; }
				if (mRules->determineWinner(mPairOfRoundMoves) == 1) { break; } //If beats someone

				if ((j == uniqueMoves.size() - 1 && mRules->determineWinner(mPairOfRoundMoves) == 2)
					|| (i == uniqueMoves.size() - 1 && j == uniqueMoves.size() - 2 && mRules->determineWinner(mPairOfRoundMoves) == 2))
				{
					uniqueMoves.erase(uniqueMoves.begin() + i);
					i = -1;
					break;
				}
			}
		}

		if (uniqueMoves.size() != 1 && !uniqueMoves.empty())
		{
			mEventCallback(Event::CantDetermineLooser);
			continue;
		}
		else
		{
			//Remove losers
			for (int i = static_cast<int>(mVectorofMassiveRoundMoves.size()) - 1; i >= 0; --i)
			{
				if (mVectorofMassiveRoundMoves[i] != uniqueMoves[0])
				{
					mPlayers.erase(mPlayers.begin() + i);
				}
			}

			break;
		}
	}
}
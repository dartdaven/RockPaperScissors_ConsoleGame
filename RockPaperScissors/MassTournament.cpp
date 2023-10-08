#include "MassTournament.h"

#include <iostream>
#include <set>
#include <vector>
#include <Windows.h>

#include "Enums.h"

void MassTournament::Play()
{
	mEventCallback(Event::TournamentStarted);

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
		
		std::vector<Move> vectorOfMassiveRoundMoves;
		vectorOfMassiveRoundMoves.reserve(mPlayers.size());

		for (const auto& player : mPlayers)
		{
			vectorOfMassiveRoundMoves.push_back(player->makeMove(mRules));
			mEventCallback(Event::PlayerMadeMove);
		}
		mEventCallback(Event::AllPlayersMadeMoves);

		std::set<Move> tempUniqueMoves(vectorOfMassiveRoundMoves.begin(), vectorOfMassiveRoundMoves.end());
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
				std::pair<Move, Move> pairOfRoundMoves = { uniqueMoves[i], uniqueMoves[j] };
				if (i == j) { continue; }
				if (mRules->determineWinner(pairOfRoundMoves) == 1) { break; } //If beats someone

				if ((j == uniqueMoves.size() - 1 && mRules->determineWinner(pairOfRoundMoves) == 2)
					|| (i == uniqueMoves.size() - 1 && j == uniqueMoves.size() - 2 && mRules->determineWinner(pairOfRoundMoves) == 2))
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
			for (int i = static_cast<int>(vectorOfMassiveRoundMoves.size()) - 1; i >= 0; --i) //static cast to avoid warning
			{
				if (vectorOfMassiveRoundMoves[i] != uniqueMoves[0])
				{
					mPlayers.erase(mPlayers.begin() + i);
				}
			}

			break;
		}
	}
	mEventCallback(Event::RoundEnded);
}
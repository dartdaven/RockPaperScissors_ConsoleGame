#include "MassTournament.h"

#include <iostream>
#include <set>
#include <vector>
#include <Windows.h>

#include "Enums.h"

void deleteLosers(const int& losersMove)
{

}

void MassTournament::PlayMassRound()
{
	while (true)
	{
		clearConsoleSmoothly();
		ShowRulesAndScore();

		std::vector<int> moves;

		//Main cycle
		for (const auto& player : players)
		{
			if (player->getName() != "Computer")
			{
				std::cout << player->getName() << ", please make your move: ";
			}
			moves.push_back(player->makeMove(rules->getAmountOfMoves()));
			
			clearConsoleSmoothly();
			ShowRulesAndScore();
		}

		std::cout << "Here are all the moves:\n";
		for (int i = 0; i < players.size(); ++i)
		{
			std::cout << players[i]->getName() << " chose: " << moveToString(rules->getMove(moves[i])) << "\n";
		}
		std::cout << "\n";
		Sleep(4000);


		std::set<int> tempUniqueMoves(moves.begin(), moves.end());
		if (tempUniqueMoves.size() == rules->getAmountOfMoves() || tempUniqueMoves.size() == 1)
		{
			std::cout << "It is not possible to determine a winner or looser. Play again\n";
			Sleep(3000);
			continue;
		}

		std::vector<int> uniqueMoves(tempUniqueMoves.begin(), tempUniqueMoves.end());

		//Check if there is move that can beat someone and nobody beats him
		for (int i = 0; i < uniqueMoves.size() && uniqueMoves.size() != 1; ++i)
		{
			for (int j = 0; j < uniqueMoves.size(); ++j)
			{
				if (i == j) { continue;  }
				if (rules->determineWinner(uniqueMoves[i], uniqueMoves[j]) == 1) { break; } //If beats someone

				if ((j == uniqueMoves.size() - 1 && rules->determineWinner(uniqueMoves[i], uniqueMoves[j]) == 2)
					|| (i == uniqueMoves.size() - 1 && j == uniqueMoves.size() - 2 && rules->determineWinner(uniqueMoves[i], uniqueMoves[j]) == 2))
				{
					uniqueMoves.erase(uniqueMoves.begin() + i);
					i = -1;
					break;
				}
			}
		}

		if (uniqueMoves.size() != 1 && !uniqueMoves.empty())
		{
			std::cout << "It was not possible to determine a winner or looser. Play again\n";
			Sleep(3000);
			continue;
		}
		else
		{
			//Delete losers
			for (int i = static_cast<int>(moves.size()) - 1; i >= 0; --i)
			{
				if (moves[i] != uniqueMoves[0])
				{
					players.erase(players.begin() + i);
				}
			}

			break;
		}
	}
}

void MassTournament::Play()
{

	while (true)
	{
		PlayMassRound();

		if (players.size() > 1)
		{
			std::cout << "So we got several lucky guys\n";
			Sleep(2000);

			for (const auto& player : players)
			{
				std::cout << player->getName() << ", ";
			}
			std::cout << "will play the tournament again till the winner will be determined\n";
			Sleep(3000);
		}
		else { break; }
	}

	std::cout << "Congratulations to the " << players[0]->getName() << ", the winner of the tournament\n";
	std::cin.get();
	return;
}


void MassTournament::ShowRulesAndScore()
{
	std::cout << "Game mode - Massive, Rules - " << rulesToString(rules->getRules()) << "\n";
	std::cout << rules->stringOfPossibleMoves() << "\n\n";
}
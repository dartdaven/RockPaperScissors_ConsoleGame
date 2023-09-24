#include "EachVsEachTournamentUI.h"

#include <cassert>
#include <Windows.h>

#include "GeneralUI.h"

bool EachVsEachTournamentUI::onEvent(const Event& event) const
{
	if (BaseTournamentUI::onEvent(event)) { return true; }

	std::shared_ptr<BaseTournament> tournamentPtr;
	if (tournamentPtr = tournament.lock()) {}
	else { assert(false); }

	switch (event)
	{
	case Event::MainCycleEnded:
		GeneralUI::clearConsoleSmoothly();

		std::cout << "\nHere's the current standings of the tournament:\n";
		for (const auto& player : tournamentPtr->getPlayers())
		{
			std::cout << player->getName() << " : " << player->getScore() << ";\n";
		}

		Sleep(3000);

		return true;

	case Event::TournamentEnded:
		winnerOfTheTournament(tournamentPtr->getPlayers()[0]->getName());
		return true;

	case Event::TwoHighScorers:

		{
			std::pair< std::shared_ptr<BasePlayer>, std::shared_ptr<BasePlayer>> pairOfRoundPlayers = tournamentPtr->getPairOfRoundPlayers();

			std::cout << "\nWe have 2 guys with high score, but only one can win the tournament\n";
			std::cout << "So it's the Duel then with rules of the tournament between " << pairOfRoundPlayers.first->getName()
				<< " and " << pairOfRoundPlayers.second->getName() << "\n";
			Sleep(5000);
		}
		return true;

	case Event::CantDetermineTheWinner:

		std::cout << "\nCan't determine the winner\n";
		for (int i = 0; i < tournamentPtr->getPlayers().size(); ++i)
		{
			if (i != tournamentPtr->getPlayers().size() - 1)
			{
				std::cout << tournamentPtr->getPlayers()[i]->getName() << ", ";
			}
			else
			{
				std::cout << tournamentPtr->getPlayers()[i]->getName() << " ";
			}
		}
		std::cout << "will play the tournament again till the winner will be determined\n";
		Sleep(5000);
		return true;
	}

	return false;
}

void EachVsEachTournamentUI::showRules() const
{
	std::shared_ptr<BaseTournament> tournamentPtr;
	if (tournamentPtr = tournament.lock())
	{
		std::cout << "Game mode - " << tournamentPtr->getName() << " | Rules - " << GeneralUI::rulesToString(tournamentPtr->getRules()->getRules())
			<< " | Wins for Victory - " << tournamentPtr->getWins4Victory() << "\n";
		std::cout << stringOfPossibleMoves(tournamentPtr->getRules()->getPossibleMoves()) << "\n\n";
	}
}
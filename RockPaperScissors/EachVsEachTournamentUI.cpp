#include "EachVsEachTournamentUI.h"

#include <Windows.h>

#include "GeneralUI.h"

bool EachVsEachTournamentUI::onEvent(const Event& event) const
{
	if (BaseTournamentUI::onEvent(event)) { return true; }

	switch (event)
	{
	case Event::MainCycleEnded:
		GeneralUI::clearConsoleSmoothly();

		std::cout << "\nHere's the current standings of the tournament:\n";
		for (const auto& player : tournament->getPlayers())
		{
			std::cout << player->getName() << " : " << player->getScore() << ";\n";
		}

		Sleep(3000);

		return true;

	case Event::TournamentEnded:
		winnerOfTheTournament(tournament->getPlayers()[0]->getName());
		return true;

	case Event::TwoHighScorers:

		{
			std::pair< std::shared_ptr<BasePlayer>, std::shared_ptr<BasePlayer>> pairOfRoundPlayers = tournament->getPairOfRoundPlayers();

			std::cout << "\nWe have 2 guys with high score, but only one can win the tournament\n";
			std::cout << "So it's the Duel then with rules of the tournament between " << pairOfRoundPlayers.first->getName()
				<< " and " << pairOfRoundPlayers.second->getName() << "\n";
			Sleep(5000);
		}
		return true;

	case Event::CantDetermineTheWinner:

		std::cout << "\nCan't determine the winner\n";
		for (int i = 0; i < tournament->getPlayers().size(); ++i)
		{
			if (i != tournament->getPlayers().size() - 1)
			{
				std::cout << tournament->getPlayers()[i]->getName() << ", ";
			}
			else
			{
				std::cout << tournament->getPlayers()[i]->getName() << " ";
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
	std::cout << "Game mode - " << tournament->getName() << " | Rules - " << rulesToString(tournament->getRules()->getRules()) 
		<< " | Wins for Victory - " << tournament->getWins4Victory() << "\n";
	std::cout << stringOfPossibleMoves(tournament->getRules()->getPossibleMoves()) << "\n\n";
}
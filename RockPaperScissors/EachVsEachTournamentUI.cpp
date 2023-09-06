#include "EachVsEachTournamentUI.h"

#include <Windows.h>

#include "GeneralUI.h"

void EachVsEachTournamentUI::onTournamentEvent(const Event& event) const
{
	switch (event)
	{
	case Event::AllPlayersMadeMoves:
		GeneralUI::clearConsoleSmoothly();
		
		std::cout << "\nHere's the current standings of the tournament:\n";
		for (const auto& player : tournament->getPlayers())
		{
			std::cout << player->getName() << " : " << player->getScore() << ";\n";
		}

		Sleep(3000);

		break;

	case Event::TournamentEnded:
		winnerOfTheTournament(tournament->getPlayers()[0]->getName());
		break;

	case Event::TwoHighScorers:

		{
			std::pair< std::unique_ptr<BasePlayer>&, std::unique_ptr<BasePlayer>& >* PairOfPlayers = tournament->getPairOfPlayers();
		
			std::cout << "\nWe have 2 guys with high score, but only one can win the tournament\n";
			std::cout << "So it's the Duel then with rules of the tournament between " << (*PairOfPlayers).first->getName()
				<< " and " << (*PairOfPlayers).second->getName() << "\n";
			Sleep(5000);
		}
		break;

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
		break;
	}
}

void EachVsEachTournamentUI::showRules() const
{
	std::cout << "Game mode - " << tournament->getName() << " | Rules - " << rulesToString(tournament->getRules()->getRules()) 
		<< " |  Wins for Victory - " << tournament->getWins4Victory() << "\n";
	std::cout << stringOfPossibleMoves(tournament->getRules()->getPossibleMoves()) << "\n\n";
}

void EachVsEachTournamentUI::showScore() const
{
}

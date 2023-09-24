#include "DuelTournamentUI.h"

#include <Windows.h>

#include "GeneralUI.h"
#include "Enums.h"

void DuelTournamentUI::showRules() const
{
	std::shared_ptr<BaseTournament> tournamentPtr;
	if (tournamentPtr = tournament.lock())
	{
		std::cout << "Game mode - " << tournamentPtr->getName() << " | Rules - " << GeneralUI::rulesToString(tournamentPtr->getRules()->getRules()) << "\n";
		std::cout << stringOfPossibleMoves(tournamentPtr->getRules()->getPossibleMoves()) << "\n\n";
	}
}

void DuelTournamentUI::showScore() const
{
	std::shared_ptr<BaseTournament> tournamentPtr;
	if (tournamentPtr = tournament.lock())
	{
		std::pair< std::shared_ptr<BasePlayer>, std::shared_ptr<BasePlayer>> pairOfRoundPlayers = tournamentPtr->getPairOfRoundPlayers();
		std::cout << pairOfRoundPlayers.first->getName() << "'s score - " << pairOfRoundPlayers.first->getScore()
			<< "     " << pairOfRoundPlayers.second->getName() << "'s score - " << pairOfRoundPlayers.second->getScore() << "\n\n";
	}
}

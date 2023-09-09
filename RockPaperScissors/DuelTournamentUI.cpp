#include "DuelTournamentUI.h"

#include <Windows.h>

#include "GeneralUI.h"
#include "Enums.h"

void DuelTournamentUI::showRules() const
{
	std::cout << "Game mode - " << tournament->getName() << " | Rules - " << rulesToString(tournament->getRules()->getRules()) << "\n";
	std::cout << stringOfPossibleMoves(tournament->getRules()->getPossibleMoves()) << "\n\n";
}

void DuelTournamentUI::showScore() const
{
	std::pair< std::shared_ptr<BasePlayer>, std::shared_ptr<BasePlayer>> pairOfRoundPlayers = tournament->getPairOfRoundPlayers();

	std::cout << pairOfRoundPlayers.first->getName() << "'s score - " << pairOfRoundPlayers.first->getScore()
		<< "     " << pairOfRoundPlayers.second->getName() << "'s score - " << pairOfRoundPlayers.second->getScore() << "\n\n";
}

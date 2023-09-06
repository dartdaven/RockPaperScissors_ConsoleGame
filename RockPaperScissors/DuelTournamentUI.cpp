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
	std::pair< std::unique_ptr<BasePlayer>&, std::unique_ptr<BasePlayer>& >* PairOfPlayers = tournament->getPairOfPlayers();

	std::cout << (*PairOfPlayers).first->getName() << "'s score - " << (*PairOfPlayers).first->getScore()
		<< "     " << (*PairOfPlayers).second->getName() << "'s score - " << (*PairOfPlayers).second->getScore() << "\n\n";
}

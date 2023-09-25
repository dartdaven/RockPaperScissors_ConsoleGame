#include "DuelTournamentUI.h"

void DuelTournamentUI::showScore() const
{
	std::shared_ptr<BaseTournament> tournamentPtr;
	if (tournamentPtr = tournament.lock())
	{
		std::pair< std::shared_ptr<BasePlayer>, std::shared_ptr<BasePlayer>> pairOfRoundPlayers = tournamentPtr->getPairOfCurrentRoundPlayers();
		std::cout << pairOfRoundPlayers.first->getName() << "'s score - " << pairOfRoundPlayers.first->getScore()
			<< "     " << pairOfRoundPlayers.second->getName() << "'s score - " << pairOfRoundPlayers.second->getScore() << "\n\n";
	}
}

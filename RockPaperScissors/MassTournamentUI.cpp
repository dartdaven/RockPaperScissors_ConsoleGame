#include "MassTournamentUI.h"

#include <cassert>
#include <Windows.h>

#include "GeneralUI.h"

bool MassTournamentUI::onEvent(const Event& event) const
{
	if (BaseTournamentUI::onEvent(event)) { return true; }

	std::shared_ptr<BaseTournament> tournamentPtr;
	if (tournamentPtr = tournament.lock()) {}
	else { assert(false); }

	switch (event)
	{
	case Event::MainCycleEnded:
		std::cout << "Here are all the moves:\n";
		{
			auto players = tournamentPtr->getPlayers();
			auto moves = tournamentPtr->getVectorofMassiveRoundMoves();

			for (int i = 0; i < players.size(); ++i)
			{
				std::cout << players[i]->getName() << " chose: "
					<< moveToString(moves[i]) << "\n";
			}
			std::cout << "\n";
			Sleep(4000);
		}
		return true;

	case Event::CantDetermineLooser:
		std::cout << "It is not possible to determine a winner or looser. Play again\n";
		Sleep(3000);
		return true;
	
	//same as EvE tournament
	case Event::CantDetermineTheWinner:
		std::cout << "So we got several lucky guys\n";
		Sleep(2000);

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
		Sleep(3000);
		return true;

	//same as EvE tournament
	case Event::TournamentEnded:
		winnerOfTheTournament(tournamentPtr->getPlayers()[0]->getName());
		return true;
	}

	return false;
}

//same as DuelTournament
void MassTournamentUI::showRules() const
{
	std::shared_ptr<BaseTournament> tournamentPtr;
	if (tournamentPtr = tournament.lock())
	{
		std::cout << "Game mode - " << tournamentPtr->getName() << " | Rules - " << rulesToString(tournamentPtr->getRules()->getRules()) << "\n";
		std::cout << stringOfPossibleMoves(tournamentPtr->getRules()->getPossibleMoves()) << "\n\n";
	}
}

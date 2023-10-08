#include "GridTournamentUI.h"

#include <Windows.h>
#include <cassert>

#include <thread>
#include <chrono>
#include <conio.h>

#include "../Misc/GeneralUI.h"
#include "../Misc/GridCell.h"


GridTournamentUI::GridTournamentUI(std::shared_ptr<BaseTournament>& tournament)
	: BaseTournamentUI(tournament)
{
	SetConsoleOutputCP(CP_UTF8);

	//Allocate the grid
	unsigned short tours = static_cast<unsigned short>(ceil(log2(tournament->getPlayers().size())));
	unsigned short gridBase = static_cast<unsigned short>(pow(2, tours));
	mGrid = std::vector<std::vector<GridCell>> (tours);
	
	for (int i = 0, k = gridBase; i < mGrid.size(); ++i, k /= 2) {
		mGrid[i].reserve(k);
	}
	
	//Fill the grid
	for (int i = 0; i < tournament->getPlayers().size(); ++i)
	{
		mGrid[0].emplace_back(tournament->getPlayers()[i]->getName());
	}
	if (tournament->getPlayers().size() % 2)
	{
		mGrid[0].emplace_back(mComputerName);
	}

}

bool GridTournamentUI::onEvent(const Event& event) const
{
	std::shared_ptr<BaseTournament> tournamentPtr;
	if (tournamentPtr = tournament.lock()) {}
	else { assert(false); }

	switch (event)
	{
	case Event::RoundStarted:
		GeneralUI::clearConsoleSmoothly();
		showRules();
		showGrid();
		BaseTournamentUI::onEvent(event);
		return true;
	
	case Event::PlayerMadeMove:
		BaseTournamentUI::onEvent(event);
		return true;

	case Event::AllPlayersMadeMoves:
		BaseTournamentUI::onEvent(event);
		return true;

	case Event::RoundEnded:
	{
 		BaseTournamentUI::onEvent(event);

		{
			BaseTournament::PairOfPlayersSignature pairOfRoundPlayers = tournamentPtr->getPairOfCurrentRoundPlayers();

			if (mCurrentTour != mGrid.size() - 1)
			{
				if (tournamentPtr->getPairOfRoundWins().first == tournamentPtr->getWins4Victory())
				{
					mGrid[mCurrentTour + 1].emplace_back(pairOfRoundPlayers.first->getName());
				}
				else
				{
					if (!pairOfRoundPlayers.second->isBot())
					{
						mGrid[mCurrentTour + 1].emplace_back(pairOfRoundPlayers.second->getName());
					}
				}
			}
		}

		++mCurrentRound;
		return true;
	}

	case Event::TournamentEnded:
		if (tournamentPtr->getPlayers().size() == 1)
		{
			winnerOfTheTournament(tournamentPtr->getPlayers()[0]->getName());
		}
		else
		{
			winnerOfTheTournament(mComputerName);
		}
		return true;

	case Event::MainCycleEnded:
		
		++mCurrentTour;
		mCurrentRound = 0;

		if (mCurrentTour < mGrid.size() && mGrid[mCurrentTour].size() % 2)
		{
			mGrid[mCurrentTour].emplace_back(mComputerName);
		}

		return true;
	}
	
	if (BaseTournamentUI::onEvent(event)) { return true; }

	std::cerr << "Wrong tournament Event has been passed";
	assert(false);
	return false;
}

//same as Each vs Each
void GridTournamentUI::showRules() const
{
	std::shared_ptr<BaseTournament> tournamentPtr;
	if (tournamentPtr = tournament.lock())
	{
		std::cout << "Game mode - " << tournamentPtr->getName() << " | Rules - " << GeneralUI::rulesToString(tournamentPtr->getRules()->getRules())
			<< " | Wins for Victory - " << tournamentPtr->getWins4Victory() << "\n";
		std::cout << stringOfPossibleMoves(tournamentPtr->getRules()->getPossibleMoves()) << "\n\n";
	}
}

void GridTournamentUI::showGrid() const
{
	while (_kbhit()) { static_cast<void>(_getche()); } //Clear input buffer

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD initialPosition{ 0, 3 };
	COORD position = initialPosition;

	auto goDown = [&]() {
		++position.Y;
		SetConsoleCursorPosition(hConsole, position);
	};

	while (!_kbhit())
	{
		SetConsoleCursorPosition(hConsole, initialPosition);
		position = initialPosition;

		for (int tourNumber = 0; tourNumber < mGrid.size(); ++tourNumber) {

			//Output Players
			int playersIterator{ 0 };

			while (playersIterator < mGrid[tourNumber].size()) {
				for (int i = 0; (i < pow(2, tourNumber) - 1); ++i) {
					goDown();
				}

				std::cout << mGrid[tourNumber][playersIterator].showCell();
				++playersIterator;
				goDown();

				if (playersIterator < mGrid[tourNumber].size())
				{
					std::cout << mGrid[tourNumber][playersIterator].showCell();
					++playersIterator;
					goDown();
				}

				for (int i = 0; (i < pow(2, tourNumber) - 1); ++i) {
					goDown();
				}
			}

			position.X += mCellSize + 1;
			position.Y = initialPosition.Y;
			SetConsoleCursorPosition(hConsole, position);

			//Draw Grid Elements
			unsigned short times = static_cast<unsigned short>(mGrid[tourNumber].capacity()) / 4;

			if (tourNumber == 0) {
				for (int i = 0; i < times; ++i) {
					for (int j = 0; j < 4; ++j) {
						std::cout << mSymbols[j];
						goDown();
					}
				}
			}
			else {
				for (int i = 0; i < times; ++i) {
					for (int i = 0; (i < pow(2, tourNumber) - 1); ++i) {
						goDown();
					}

					//Magic numbers Warning
					std::cout << mSymbols[0];
					goDown();
					std::cout << mSymbols[4];
					goDown();

					for (int i = 0; (i < pow(2, tourNumber) - 2); ++i) {
						std::cout << mSymbols[7];
						goDown();
					}

					std::cout << mSymbols[5];
					goDown();
					std::cout << mSymbols[6];
					goDown();

					for (int i = 0; (i < pow(2, tourNumber) - 2); ++i) {
						std::cout << mSymbols[7];
						goDown();
					}

					std::cout << mSymbols[4];
					goDown();
					std::cout << mSymbols[3];
					goDown();

					for (int i = 0; (i < pow(2, tourNumber) - 1); ++i) {
						goDown();
					}
				}
			}

			if (tourNumber != mGrid.size() - 1) {
				position.X += 4 ; //Magic number, because symbols are larger size
				position.Y = initialPosition.Y;
				SetConsoleCursorPosition(hConsole, position);
			}
			else {
				position.Y = initialPosition.Y + static_cast<SHORT>(pow(2, mGrid.size()));
				SetConsoleCursorPosition(hConsole, position);
				std::cout << "\nPress any key to continue...";
			}
		}
		
		//TODO blink only needed elements, not the whole grid
		mGrid[mCurrentTour][mCurrentRound * 2].swapVisibility();
		mGrid[mCurrentTour][(mCurrentRound * 2) + 1].swapVisibility();
		
		Sleep(500);
	}

	mGrid[mCurrentTour][mCurrentRound * 2].setToVisible();
	mGrid[mCurrentTour][(mCurrentRound * 2) + 1].setToVisible();
	
	static_cast<void>(_getch());
}

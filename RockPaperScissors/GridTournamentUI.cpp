#include "GridTournamentUI.h"

#include <Windows.h>
#include <cassert>

#include <thread>
#include <chrono>
#include <conio.h>

#include "GeneralUI.h"


GridTournamentUI::GridTournamentUI(std::shared_ptr<BaseTournament>& tournament)
	: BaseTournamentUI(tournament)
{
	SetConsoleOutputCP(CP_UTF8);

	mEmptyCell = std::string(mCellSize, ' ');
	mGridCells = std::vector<std::string>(14, mEmptyCell);

	//fill the grid
	for (int i = 0; i < tournament->getPlayers().size(); ++i)
	{
		WriteToCell(i, tournament->getPlayers()[i]->getName());
	}
	if (tournament->getPlayers().size() % 2)
	{
		WriteToCell(static_cast<int>(tournament->getPlayers().size()), "Computer");
	}

	//choose the grid
	if (tournament->getPlayers().size() > 4) {
		ShowGrid = std::bind(&GridTournamentUI::ShowGrid8, this);
	}
	else {
		ShowGrid = std::bind(&GridTournamentUI::ShowGrid4, this);
	}
}

bool GridTournamentUI::onEvent(const Event& event) const
{
	if (BaseTournamentUI::onEvent(event)) { return true; }

	std::shared_ptr<BaseTournament> tournamentPtr;
	if (tournamentPtr = tournament.lock()) {}
	else { assert(false); }

	switch (event)
	{
	case Event::GridRoundStarted:
		GeneralUI::clearConsoleSmoothly();
		showRules();
		ShowGrid();
		return true;
	
	case Event::GridRoundEnded:
	{
		int CellToWrite{};

		//hardcode don't like it
		if (mCurrentRound == 1) { CellToWrite = 8; }
		if (mCurrentRound == 2) { CellToWrite = 9; }
		if (mCurrentRound == 3) { CellToWrite = 10; }
		if (mCurrentRound == 4) { CellToWrite = 11; }
		if (mCurrentRound == 5) { CellToWrite = 12; }
		if (mCurrentRound == 6) { CellToWrite = 13; }

		{
			std::pair< std::shared_ptr<BasePlayer>, std::shared_ptr<BasePlayer>> pairOfRoundPlayers = tournamentPtr->getPairOfRoundPlayers();
			if (pairOfRoundPlayers.first->getScore() > pairOfRoundPlayers.second->getScore())
			{
				WriteToCell(CellToWrite, pairOfRoundPlayers.first->getName());
			}
			else
			{
				WriteToCell(CellToWrite, pairOfRoundPlayers.second->getName());
			}
		}

		mCurrentRound++;
		return true;
	}

	case Event::TournamentEnded:
		if (tournamentPtr->getPlayers().size() == 1)
		{
			winnerOfTheTournament(tournamentPtr->getPlayers()[0]->getName());
		}
		else
		{
			winnerOfTheTournament("Computer");
		}
		return true;

	case Event::MainCycleEnded:
		if (mCurrentRound < 5) 
		{ 
			mCurrentRound = 5;
			if (tournamentPtr->getPlayers().size() % 2)
			{
				WriteToCell(11, "Computer");
			}
		}
		else if (mCurrentRound > 5 && mCurrentRound < 7) 
		{ 
			mCurrentRound = 7;
			if (tournamentPtr->getPlayers().size() % 2)
			{
				WriteToCell(13, "Computer");
			}
		}
		return true;
	}

	return false;
}

//same as Each vs Each need to remove
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

void GridTournamentUI::ShowGrid8() const
{
	//hardcode don't like it
	bool Round1{ 1 }, Round2{ 1 }, Round3{ 1 }, Round4{ 1 }, Round5{ 1 }, Round6{ 1 }, Round7{ 1 };

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD start;
	start.X = 0;
	start.Y = 3;

	while (!_kbhit())
	{
		SetConsoleCursorPosition(hConsole, start);

		std::cout << (Round1 ? mGridCells[0] : mEmptyCell) << " ─┐" << "\n";
		std::cout << (Round1 ? mGridCells[1] : mEmptyCell) << " ─┴─ " << (Round5 ? mGridCells[8] : mEmptyCell) << " ─┐" << "\n";
		std::cout << (Round2 ? mGridCells[2] : mEmptyCell) << " ─┬─ " << (Round5 ? mGridCells[9] : mEmptyCell) << " ─┤" << "\n";
		std::cout << (Round2 ? mGridCells[3] : mEmptyCell) << " ─┘  " << mEmptyCell << "  └─ " << (Round7 ? mGridCells[12] : mEmptyCell) << "\n";
		std::cout << (Round3 ? mGridCells[4] : mEmptyCell) << " ─┐  " << mEmptyCell << "  ┌─ " << (Round7 ? mGridCells[13] : mEmptyCell) << "\n";
		std::cout << (Round3 ? mGridCells[5] : mEmptyCell) << " ─┴─ " << (Round6 ? mGridCells[10] : mEmptyCell) << " ─┤" << "\n";
		std::cout << (Round4 ? mGridCells[6] : mEmptyCell) << " ─┬─ " << (Round6 ? mGridCells[11] : mEmptyCell) << " ─┘" << "\n";
		std::cout << (Round4 ? mGridCells[7] : mEmptyCell) << " ─┘" << "\n\n";
		std::cout << "Press any key to continue...\n";

		//hardcode don't like it
		if (mCurrentRound == 1) { Round1 = !Round1; }
		if (mCurrentRound == 2) { Round2 = !Round2; }
		if (mCurrentRound == 3) { Round3 = !Round3; }
		if (mCurrentRound == 4) { Round4 = !Round4; }
		if (mCurrentRound == 5) { Round5 = !Round5; }
		if (mCurrentRound == 6) { Round6 = !Round6; }
		if (mCurrentRound == 7) { Round7 = !Round7; }
		
		Sleep(500);
	}
	char fake = _getch();
}

void GridTournamentUI::ShowGrid4() const
{
	//hardcode don't like it
	bool Round1{ 1 }, Round2{ 1 }, Round5{ 1 };

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD start;
	start.X = 0;
	start.Y = 3;

	while (!_kbhit())
	{
		SetConsoleCursorPosition(hConsole, start);

		std::cout << (Round1 ? mGridCells[0] : mEmptyCell) << " ─┐" << "\n";
		std::cout << (Round1 ? mGridCells[1] : mEmptyCell) << " ─┴─ " << (Round5 ? mGridCells[8] : mEmptyCell) << "\n";
		std::cout << (Round2 ? mGridCells[2] : mEmptyCell) << " ─┬─ " << (Round5 ? mGridCells[9] : mEmptyCell) << "\n";
		std::cout << (Round2 ? mGridCells[3] : mEmptyCell) << " ─┘ " << "\n\n";
		std::cout << "Press any key to continue...\n";

		//hardcode don't like it
		if (mCurrentRound == 1) { Round1 = !Round1; }
		if (mCurrentRound == 2) { Round2 = !Round2; }
		if (mCurrentRound == 5) { Round5 = !Round5; }
		
		Sleep(500);
	}
	char fake = _getch();
}

void GridTournamentUI::WriteToCell(int cellNumber, const std::string& whatToWrite) const
{
	std::string temp = whatToWrite;
	if (temp.size() > mGridCells[0].size()) { temp.resize(mGridCells[0].size()); }

	//May be need to "clear" it before 
	mGridCells[cellNumber].replace(0, temp.size(), temp);
}

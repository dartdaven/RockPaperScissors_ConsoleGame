#include "GridTournament.h"

#include <iostream>
#include <Windows.h>

void GridTournament::Play()
{
	//int cellSize{ 8 };
	//gridCells = std::vector<std::string>(14, std::string(cellSize, ' '));

	//for (int i = 0; i < players.size(); ++i)
	//{
	//	//Warning for > 8 !!
	//	writeToCell(i, players[i]->getName());
	//}

	//ShowGrid();

	//for (int i = 0; i < players.size(); i = i + 2)
	//{
	//	PlayRound(i, i + 1);
	//}

	//for (int i = players.size() - 1; i >= 0; --i)
	//{
	//	if (players[i]->getScore() != 1)
	//	{
	//		players.erase(players.begin() + i);
	//	}
	//}

	//int cellCount = 8;
	//for (const auto& player : players)
	//{
	//	writeToCell(cellCount, player->getName());
	//	++cellCount;
	//}

	//ShowGrid();

	//for (int i = 0; i < players.size(); i = i + 2)
	//{
	//	PlayRound(i, i + 1);
	//}

	//for (int i = players.size() - 1; i >= 0; --i)
	//{
	//	if (players[i]->getScore() != 2)
	//	{
	//		players.erase(players.begin() + i);
	//	}
	//}

	//for (const auto& player : players)
	//{
	//	writeToCell(cellCount, player->getName());
	//	++cellCount;
	//}

	//ShowGrid();

	//for (int i = 0; i < players.size(); i = i + 2)
	//{
	//	PlayRound(i, i + 1);
	//}

	//for (int i = players.size() - 1; i >= 0; --i)
	//{
	//	if (players[i]->getScore() != 3)
	//	{
	//		players.erase(players.begin() + i);
	//	}
	//}

	//std::cout << "Congratulations to the " << players[0]->getName() << ", the winner of the tournament\n";
	//std::cin.get();
	//return;
}

//void GridTournament::ShowRulesAndScore()
//{
//	std::cout << "Game mode - Each vs Each, Rules - " << BaseGameRules::rulesToString(rules->getRules()) << ", Wins for Victory - " << wins4Victory << "\n";
//	std::cout << rules->stringOfPossibleMoves() << "\n\n";
//}


void GridTournament::ShowGrid()
{
	//clearConsoleSmoothly();
	//ShowRulesAndScore();

	//std::cout << gridCells[0] << " ─┐" << "\n";
	//std::cout << gridCells[1] << " ─┴─ " << gridCells[8] << " ─┐" << "\n";
	//std::cout << gridCells[2] << " ─┬─ " << gridCells[9] << " ─┤" << "\n";
	//std::cout << gridCells[3] << " ─┘  " << std::string(gridCells[0].size(), ' ') << " └─ " << gridCells[12] << "\n";
	//std::cout << gridCells[4] << " ─┐  " << std::string(gridCells[0].size(), ' ') << " ┌─ " << gridCells[13] << "\n";
	//std::cout << gridCells[5] << " ─┴─ " << gridCells[10] << " ─┤" << "\n";
	//std::cout << gridCells[6] << " ─┬─ " << gridCells[11] << " ─┘" << "\n";
	//std::cout << gridCells[7] << " ─┘" << "\n";

	//Sleep(5000);
}

void GridTournament::writeToCell(const int& cellNumber, const std::string& whatToWrite)
{
	std::string temp = whatToWrite;
	if (temp.size() > gridCells[0].size()) { temp.resize(gridCells[0].size()); }
	
	//May need to "clear" it before 
	gridCells[cellNumber].replace(0, temp.size(), temp);
}



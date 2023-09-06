#pragma once

#include "BaseTournament.h"



class GridTournament : public BaseTournament
{
public:
	using BaseTournament::BaseTournament;
	void Play() override;
private: 
	void ShowGrid();
	std::vector<std::string> gridCells;
	void writeToCell(const int& cellNumber, const std::string& whatToWrite);
};


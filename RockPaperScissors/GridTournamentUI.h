#pragma once
#include "BaseTournamentUI.h"

#include <functional>

class GridCell;

class GridTournamentUI : public BaseTournamentUI
{
public:
	GridTournamentUI(std::shared_ptr<BaseTournament>& tournament);

	virtual bool onEvent(const Event& event) const override;

	//general funcs
	void showRules() const override;
	void showScore() const override {};

	void showGrid() const;

private:
	mutable std::vector<std::vector<GridCell>> mGrid; 
	
	unsigned short mCellSize { 8 };

	mutable unsigned short mCurrentRound{ 0 };
	mutable unsigned short mCurrentTour{ 0 };

	std::string mComputerName { "Computer" };
	std::vector<std::string> mSymbols { "─┐ ", "─┴─", "─┬─", "─┘ ", "─┤ ", " └─", " ┌─", " │ " };
};


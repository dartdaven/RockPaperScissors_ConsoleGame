#pragma once
#include "BaseTournamentUI.h"

#include <functional>

class GridTournamentUI : public BaseTournamentUI
{
public:
	GridTournamentUI(std::shared_ptr<BaseTournament>& tournament);

	virtual bool onEvent(const Event& event) const override;

	//general funcs
	void showRules() const override;
	void showScore() const override {};

private:
	int mCellSize { 8 };
	std::string mEmptyCell;
	mutable std::vector<std::string> mGridCells;
	
	//should not be const
	void WriteToCell(int cellNumber, const std::string& whatToWrite) const;
	
	std::function<void()> ShowGrid;
	void ShowGrid8() const;
	void ShowGrid4() const;

	mutable int mCurrentRound{1};
};


#pragma once
#include <string>

class GridCell
{
public:
	GridCell(const std::string& content, int cellSize = 9);

	void writeToCell(const std::string& string);
	void swapVisibility() { mVisible = !mVisible; }
	void setToVisible() { mVisible = true; }
	const std::string& showCell() const { return mVisible ? mContent : mEmptyString; }



private:
	int mCellSize;
	std::string mContent;
	std::string mEmptyString;
	bool mVisible;

};


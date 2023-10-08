#include "GridCell.h"

GridCell::GridCell(const std::string& content, int cellSize) : mCellSize(cellSize), mVisible(true)
{
	writeToCell(content);
	mEmptyString = std::string(mCellSize, ' ');

}

void GridCell::writeToCell(const std::string& string)
{
	std::string temp = string;
	if (temp.size() > mCellSize) { temp.resize(mCellSize); }

	mContent = std::string (mCellSize, ' ');
	mContent.replace(0, temp.size(), temp);
}
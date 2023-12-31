#include "ComputerPlayer.h"

#include <random>

#include "../Misc/Enums.h"

Move ComputerPlayer::makeMove(const std::unique_ptr<BaseGameRules>& rules)
{
	std::uniform_int_distribution<> dist(0, static_cast<int>(rules->getPossibleMoves().size() - 1));
	mLastMoveMade = rules->getPossibleMoves()[dist(mGen)];
	return mLastMoveMade;
}

std::string ComputerPlayer::getName() const
{
	return "Computer";
}

bool ComputerPlayer::isBot() const
{
	return true;
}

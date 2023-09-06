#include "ComputerPlayer.h"

#include <random>

#include "Enums.h"

Move ComputerPlayer::makeMove(const std::unique_ptr<BaseGameRules>& rules) const
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, static_cast<int>(rules->getPossibleMoves().size() - 1));
	return rules->getPossibleMoves()[dist(gen)];
}

std::string ComputerPlayer::getName() const
{
	return "Computer";
}

bool ComputerPlayer::isBot() const
{
	return true;
}

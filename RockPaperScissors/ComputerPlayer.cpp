#include "ComputerPlayer.h"

#include <random>

int ComputerPlayer::makeMove(const int& possibleMovesAmount) const
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, possibleMovesAmount - 1);
	return dist(gen);
}

std::string ComputerPlayer::getName() const
{
	return "Computer";
}

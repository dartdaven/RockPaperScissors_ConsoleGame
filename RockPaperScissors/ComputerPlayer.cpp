#include "ComputerPlayer.h"

#include <cstdlib>
#include <ctime>

Move ComputerPlayer::MakeMove(const Rules& rules)
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	switch (rules)
	{
	case Rules::BigBang:
		return static_cast<Move>(std::rand() % 5);
	
	default:
		return static_cast<Move>(std::rand() % 3);
	}
}

std::string ComputerPlayer::getName()
{
	return "Computer";
}

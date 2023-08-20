#pragma once

#include "BasePlayer.h"

class ComputerPlayer : public BasePlayer
{
public:
	int makeMove(const int& possibleMovesAmount) const override;
	std::string getName() const override;
};


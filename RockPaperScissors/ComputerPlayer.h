#pragma once

#include "Player.h"

class ComputerPlayer : public Player
{
public:
	Move MakeMove(const Rules& rules) override;
	std::string getName() override;
};


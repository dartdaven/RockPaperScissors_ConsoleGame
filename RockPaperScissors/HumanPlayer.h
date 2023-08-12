#pragma once

#include <string>

#include "Player.h"

class HumanPlayer : public Player
{
public:
	Move MakeMove(const Rules& rules) override;
	std::string getName();

private:
	std::string name;
};


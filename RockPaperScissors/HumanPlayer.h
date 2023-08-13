#pragma once

#include <string>

#include "Player.h"

class HumanPlayer : public Player
{
public:
	HumanPlayer(const std::string& name) : name(name) {}
	HumanPlayer() : name("Player") {}

	Move MakeMove(const Rules& rules) override;
	std::string getName();

private:
	std::string name;
};


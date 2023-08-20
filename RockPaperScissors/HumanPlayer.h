#pragma once

#include <string>

#include "BasePlayer.h"

class HumanPlayer : public BasePlayer
{
public:
	HumanPlayer(const std::string& name = "Player") : name(name) {}

	int makeMove(const int& possibleMovesAmount) const override;
	std::string getName() const override;

private:
	std::string name;
};


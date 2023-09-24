#pragma once

#include <string>

#include "BasePlayer.h"

class HumanPlayer : public BasePlayer
{
public:
	HumanPlayer(const std::string& name = "Player") : name(name) {}

	Move makeMove(const std::unique_ptr<BaseGameRules>& rules) const override;
	std::string getName() const override { return name; };
	bool isBot() const override { return false; };

private:
	std::string name;
};


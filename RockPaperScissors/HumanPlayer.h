#pragma once

#include <string>

#include "BasePlayer.h"

class HumanPlayer : public BasePlayer
{
public:
	HumanPlayer(const std::string& name = "Player") : name(name) {}

	Move makeMove(const std::unique_ptr<BaseGameRules>& rules) const override;
	std::string getName() const override;
	bool isBot() const override;

private:
	std::string name;
};


#pragma once

#include "BasePlayer.h"

class ComputerPlayer : public BasePlayer
{
public:
	Move makeMove(const std::unique_ptr<BaseGameRules>& rules) override;
	std::string getName() const override;
	bool isBot() const override;
};


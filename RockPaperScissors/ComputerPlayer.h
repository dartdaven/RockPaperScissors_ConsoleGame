#pragma once

#include "BasePlayer.h"

#include <random>

class ComputerPlayer : public BasePlayer
{
public:
	ComputerPlayer() : mGen(mRd()) {}
	
	Move makeMove(const std::unique_ptr<BaseGameRules>& rules) override;
	std::string getName() const override;
	bool isBot() const override;

private:
	std::random_device mRd;
	std::mt19937 mGen;
};


#pragma once

#include <string>
#include <memory>

#include "../Rules/BaseGameRules.h"
#include "../Misc/Enums.h"

class BasePlayer
{
public:
	BasePlayer() : mScore(0) {}
	virtual ~BasePlayer() {};

	virtual Move makeMove(const std::unique_ptr<BaseGameRules>& rules) = 0;
	virtual std::string getName() const = 0;
	virtual bool isBot() const = 0;
	
	int getScore() const { return mScore; }
	void resetScore() { mScore = 0; }
	void incrementScore() { ++mScore; }
	
	Move getLastMoveMade() const { return mLastMoveMade; }

	//for debug purposes only
	void setScore(const int& number) { mScore = number; }

protected:
	int mScore;
	Move mLastMoveMade{};
};
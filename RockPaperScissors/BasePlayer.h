#pragma once

#include <string>
#include <memory>

#include "BaseGameRules.h"
#include "Enums.h"

class BasePlayer
{
public:
	BasePlayer() : mScore(0), mWins(0) {}
	virtual ~BasePlayer() {};

	virtual Move makeMove(const std::unique_ptr<BaseGameRules>& rules) = 0;
	virtual std::string getName() const = 0;
	virtual bool isBot() const = 0;
	
	int getScore() const { return mScore; }
	void resetScore() { mScore = 0; }
	void incrementScore() { ++mScore; }
	
	int getWins() const { return mWins; }
	void resetWins() { mWins = 0; }
	void incrementWins() { ++mWins; };
	
	Move getLastMoveMade() const { return mLastMoveMade; }

	//for debug purposes only, need to delete
	void setScore(const int& number) { mScore = number; }

protected:
	int mWins;
	int mScore;
	Move mLastMoveMade{};
};
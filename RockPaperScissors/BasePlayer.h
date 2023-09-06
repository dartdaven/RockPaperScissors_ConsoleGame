#pragma once

#include <string>
#include <memory>

#include "BaseGameRules.h"
#include "Enums.h"

class BasePlayer
{
public:
	BasePlayer() : score(0), wins(0) {}
	virtual ~BasePlayer() {};

	virtual Move makeMove(const std::unique_ptr<BaseGameRules>& rules) const = 0;
	virtual std::string getName() const = 0;
	virtual bool isBot() const = 0;
	
	int getScore() const;
	void resetScore();
	void incrementScore();
	
	int getWins() { return wins; }
	void resetWins() { wins = 0; }
	void incrementWins() { ++wins; };
	
	//for debug purposes only, need to delete
	void setScore(const int& number);

protected:
	int wins;
	int score;
};
#pragma once

#include <vector>
#include <memory>

#include "GameRules.h"
#include "Player.h"

class Tournament
{
public:
	Tournament(std::vector<std::unique_ptr<Player>> players, std::unique_ptr<GameRules> rules, const int& wins4Victory)
		: players(std::move(players)), rules(std::move(rules)), wins4Victory(wins4Victory) {}
	
	Tournament(std::vector<std::unique_ptr<Player>> players, std::unique_ptr<GameRules> rules)
		: players(std::move(players)), rules(std::move(rules)), wins4Victory(1) {}
	
	virtual void Play() = 0;
	virtual void ShowRulesAndScore() = 0;

protected:
	std::vector<std::unique_ptr<Player>> players;
	std::unique_ptr<GameRules> rules;
	int wins4Victory;
};


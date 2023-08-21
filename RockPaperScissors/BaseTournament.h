#pragma once

#include <vector>
#include <memory>

#include "BaseGameRules.h"
#include "BasePlayer.h"

class BaseTournament
{
public:
	BaseTournament(std::vector<std::unique_ptr<BasePlayer>> players, std::unique_ptr<BaseGameRules> rules, const int& wins4Victory = 1)
		: players(std::move(players)), rules(std::move(rules)), wins4Victory(wins4Victory) {}
	virtual ~BaseTournament() {}
	
	virtual void Play() = 0;
	virtual void ShowRulesAndScore() = 0;
	virtual void PlayRound(int player1Index, int player2Index);

protected:
	std::vector<std::unique_ptr<BasePlayer>> players;
	std::unique_ptr<BaseGameRules> rules;
	int wins4Victory;
	
	void clearConsoleSmoothly();
};

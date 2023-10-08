#pragma once

#include <vector>
#include <memory>
#include <functional>

#include "Enums.h"
#include "BasePlayer.h"
#include "RulesFactory.h"

class BaseGameRules;

class BaseTournament
{
public:
	BaseTournament(std::vector<std::shared_ptr<BasePlayer>>&& players, Rules rules, int wins4Victory = 1)
		: mPlayers(std::move(players)), mRules(RulesFactory::generateRules(rules)), mWins4Victory(wins4Victory) {}
	virtual ~BaseTournament() {}
	
	using PairOfPlayersSignature = std::pair< std::shared_ptr<BasePlayer>, std::shared_ptr<BasePlayer>>;

	virtual void Play() = 0;

	void setEventCallback(std::function<void(const Event&)>&& callback) { mEventCallback = std::move(callback); }

	//Getters
	const std::vector<std::shared_ptr<BasePlayer>>& getPlayers() const { return mPlayers; }
	const std::unique_ptr<BaseGameRules>& getRules() const { return mRules; }
	const unsigned short& getWins4Victory() const { return mWins4Victory; }
	const std::string& getName() const { return mName; }

	//RoundGetters
	const PairOfPlayersSignature& getPairOfCurrentRoundPlayers() const { return mPairOfCurrentRoundPlayers; }
	const std::pair<int, int>& getPairOfRoundWins() const { return mPairOfRoundWins; }

protected:
	virtual void PlayRound();

	std::vector<std::shared_ptr<BasePlayer>> mPlayers;
	std::unique_ptr<BaseGameRules> mRules;
	unsigned short mWins4Victory;
	std::string mName;

	//For Round purposes
	PairOfPlayersSignature mPairOfCurrentRoundPlayers;
	std::pair<int, int> mPairOfRoundWins;
	
	//Callbacks
	std::function<void(const Event&)> mEventCallback;
};

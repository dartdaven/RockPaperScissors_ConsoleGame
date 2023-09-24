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
	virtual void PlayRound();

	void setEventCallback(std::function<void(const Event&)>&& callback) { mEventCallback = std::move(callback); }

	//Getters
	const std::vector<std::shared_ptr<BasePlayer>>& getPlayers() const { return mPlayers; }
	const std::unique_ptr<BaseGameRules>& getRules() const { return mRules; };
	const int& getWins4Victory() const { return mWins4Victory; };
	const std::string& getName() const { return mName; };

	//RoundGetters
	const PairOfPlayersSignature& getPairOfRoundPlayers() const { return mPairOfRoundPlayers; };
	const std::pair<Move, Move>& getPairOfRoundMoves() const { return mPairOfRoundMoves; };
	
	//doesn't good
	const std::vector<Move>& getVectorofMassiveRoundMoves() const { return mVectorofMassiveRoundMoves; }

protected:
	std::vector<std::shared_ptr<BasePlayer>> mPlayers;
	std::unique_ptr<BaseGameRules> mRules;
	int mWins4Victory;
	std::string mName;

	//For Round purposes
	PairOfPlayersSignature mPairOfRoundPlayers;
	std::pair<Move, Move> mPairOfRoundMoves;
	
	//doesn't good that knows about inheritance
	std::vector<Move> mVectorofMassiveRoundMoves;
	
	//Callbacks
	std::function<void(const Event&)> mEventCallback;
};

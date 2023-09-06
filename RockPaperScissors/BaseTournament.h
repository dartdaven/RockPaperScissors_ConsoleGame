#pragma once

#include <vector>
#include <memory>
#include <functional>

#include "Enums.h"
#include "BasePlayer.h"

class BaseGameRules;

class BaseTournament
{
public:
	BaseTournament(std::vector<std::unique_ptr<BasePlayer>> players, std::unique_ptr<BaseGameRules> rules, const int& wins4Victory = 1)
		: players(std::move(players)), rules(std::move(rules)), wins4Victory(wins4Victory) {}
	virtual ~BaseTournament() {}
	
	using PairOfPlayersSignature = std::pair<std::unique_ptr<BasePlayer>&, std::unique_ptr<BasePlayer>&>;

	virtual void Play() = 0;
	virtual void PlayRound(PairOfPlayersSignature pairOfPlayers);

	void setRoundEventCallback(std::function<void(const Event&)>&& callback) { roundEventCallback = std::move(callback); }
	void setTournamentEventCallback(std::function<void(const Event&)>&& callback) { tournamentEventCallback = std::move(callback); }

	//Getters
	const std::vector<std::unique_ptr<BasePlayer>>& getPlayers() const { return players; }
	const std::unique_ptr<BaseGameRules>& getRules() const { return rules; };
	const int& getWins4Victory() const { return wins4Victory; };
	const std::string& getName() const { return name; };
	PairOfPlayersSignature* getPairOfPlayers() const { return mPairOfPlayers; };
	const std::pair<Move, Move>& getPairOfMoves() const { return mPairOfMoves; };

protected:
	std::vector<std::unique_ptr<BasePlayer>> players;
	std::unique_ptr<BaseGameRules> rules;
	int wins4Victory;
	std::string name;

	//Don't like this code
	PairOfPlayersSignature* mPairOfPlayers {};
	std::pair<Move, Move> mPairOfMoves;
	
	//Callbacks
	std::function<void(const Event&)> roundEventCallback;
	std::function<void(const Event&)> tournamentEventCallback;
};

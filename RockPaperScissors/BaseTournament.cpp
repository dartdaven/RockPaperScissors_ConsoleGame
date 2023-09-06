#include "BaseTournament.h"

#include <chrono>
#include <iostream>
#include <thread>
#include <Windows.h>
#include <assert.h>

#include "BasePlayer.h"

void BaseTournament::PlayRound(PairOfPlayersSignature pairOfPlayers)
{
    if (!roundEventCallback) { assert(false); }
    mPairOfPlayers = &pairOfPlayers;

    while (pairOfPlayers.first->getWins() != wins4Victory && pairOfPlayers.second->getWins() != wins4Victory)
    {
        roundEventCallback(Event::RoundStarted);

        Move firstMove = pairOfPlayers.first->makeMove(rules);
        roundEventCallback(Event::PlayerMadeMove);

        Move secondMove = pairOfPlayers.second->makeMove(rules);
        roundEventCallback(Event::PlayerMadeMove);

        mPairOfMoves = std::pair<Move, Move>(firstMove, secondMove);

        int tempResult = rules->determineWinner(mPairOfMoves);
        
        switch (tempResult)
        {
        case 1:
            pairOfPlayers.first->incrementWins();
            break;

        case 2:
            pairOfPlayers.second->incrementWins();
            break;

        default: break;
        }

        roundEventCallback(Event::AllPlayersMadeMoves);
    }
    
    roundEventCallback(Event::RoundEnded);

    if (pairOfPlayers.first->getWins() == wins4Victory)
    {
        pairOfPlayers.first->incrementScore();
        pairOfPlayers.first->resetWins();
    }
    else
    {
        pairOfPlayers.second->incrementScore();
        pairOfPlayers.second->resetWins();
    }
}

#include "BaseTournament.h"

#include <chrono>
#include <iostream>
#include <thread>
#include <Windows.h>
#include <assert.h>

#include "BasePlayer.h"

void BaseTournament::PlayRound()
{
    assert(mEventCallback);
    assert(mPairOfRoundPlayers.first || mPairOfRoundPlayers.second);

    while (mPairOfRoundPlayers.first->getWins() != mWins4Victory && mPairOfRoundPlayers.second->getWins() != mWins4Victory)
    {
        mEventCallback(Event::RoundStarted);

        Move firstMove = mPairOfRoundPlayers.first->makeMove(mRules);
        mEventCallback(Event::PlayerMadeMove);

        Move secondMove = mPairOfRoundPlayers.second->makeMove(mRules);
        mEventCallback(Event::PlayerMadeMove);

        mPairOfRoundMoves = std::pair<Move, Move>(firstMove, secondMove);

        int tempResult = mRules->determineWinner(mPairOfRoundMoves);
        
        switch (tempResult)
        {
        case 1:
            mPairOfRoundPlayers.first->incrementWins();
            break;

        case 2:
            mPairOfRoundPlayers.second->incrementWins();
            break;

        default: break;
        }

        mEventCallback(Event::AllPlayersMadeMoves);
    }
    
    mEventCallback(Event::RoundEnded);

    if (mPairOfRoundPlayers.first->getWins() == mWins4Victory)
    {
        mPairOfRoundPlayers.first->incrementScore();
        mPairOfRoundPlayers.first->resetWins();
    }
    else
    {
        mPairOfRoundPlayers.second->incrementScore();
        mPairOfRoundPlayers.second->resetWins();
    }
}

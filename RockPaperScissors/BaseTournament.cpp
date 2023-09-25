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
    assert(mPairOfCurrentRoundPlayers.first || mPairOfCurrentRoundPlayers.second);

    mEventCallback(Event::RoundStarted);

    while (mPairOfCurrentRoundPlayers.first->getWins() != mWins4Victory && mPairOfCurrentRoundPlayers.second->getWins() != mWins4Victory)
    {
        Move firstMove = mPairOfCurrentRoundPlayers.first->makeMove(mRules);
        mEventCallback(Event::PlayerMadeMove);

        Move secondMove = mPairOfCurrentRoundPlayers.second->makeMove(mRules);
        mEventCallback(Event::PlayerMadeMove);

        std::pair<Move, Move> pairOfRoundMoves {firstMove, secondMove};

        int tempResult = mRules->determineWinner(pairOfRoundMoves);
        
        switch (tempResult)
        {
        case 1:
            mPairOfCurrentRoundPlayers.first->incrementWins();
            break;

        case 2:
            mPairOfCurrentRoundPlayers.second->incrementWins();
            break;

        default: break;
        }

        mEventCallback(Event::AllPlayersMadeMoves);
    }
    
    mEventCallback(Event::RoundEnded);
    
    if (mPairOfCurrentRoundPlayers.first->getWins() == mWins4Victory)
    {
        mPairOfCurrentRoundPlayers.first->incrementScore();
        mPairOfCurrentRoundPlayers.first->resetWins();
    }
    else
    {
        mPairOfCurrentRoundPlayers.second->incrementScore();
        mPairOfCurrentRoundPlayers.second->resetWins();
    }
}

#include "BaseTournament.h"

#include <chrono>
#include <iostream>
#include <thread>
#include <Windows.h>
#include <assert.h>

#include "../Players/BasePlayer.h"

void BaseTournament::PlayRound()
{
    assert(mEventCallback);
    assert(mPairOfCurrentRoundPlayers.first || mPairOfCurrentRoundPlayers.second);
    
    mPairOfRoundWins = { 0, 0 };

    mEventCallback(Event::RoundStarted);

    while (mPairOfRoundWins.first != mWins4Victory && mPairOfRoundWins.second != mWins4Victory)
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
            ++mPairOfRoundWins.first;
            break;

        case 2:
            ++mPairOfRoundWins.second;
            break;

        default: break;
        }

        mEventCallback(Event::AllPlayersMadeMoves);
    }
    
    
    if (mPairOfRoundWins.first == mWins4Victory) {
        mPairOfCurrentRoundPlayers.first->incrementScore();
    }
    else {
        mPairOfCurrentRoundPlayers.second->incrementScore();
    }

    mEventCallback(Event::RoundEnded);
}

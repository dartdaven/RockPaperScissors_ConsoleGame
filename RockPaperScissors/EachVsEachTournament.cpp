#include "EachVsEachTournament.h"

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
#include <windows.h>

void EachVsEachTournament::Play()
{

    //Random sorting, but everyone will play with each other
    std::vector<PairOfPlayersSignature> pairsOfPlayers;
    pairsOfPlayers.reserve((mPlayers.size() * (mPlayers.size() - 1)) / 2);

    for (int i = 0; i < mPlayers.size(); ++i)
    {
        for (int j = i + 1; j < mPlayers.size(); ++j)
        {
            pairsOfPlayers.push_back({ mPlayers[i], mPlayers[j] });
        }
    }

    std::shuffle(pairsOfPlayers.begin(), pairsOfPlayers.end(), mGen);

    mEventCallback(Event::TournamentStarted);
    
    //Main cycle
    for (auto& pair : pairsOfPlayers)
    {
        std::uniform_int_distribution<> dist(0, 1);
        if (dist(mGen))
        {
            std::swap(pair.first, pair.second);
        }
        mPairOfCurrentRoundPlayers = pair;
        PlayRound();
    }

    mEventCallback(Event::MainCycleEnded);

    //delete loosers
    int maxScore = mPlayers[0]->getScore();
    for (int i = 0; i < mPlayers.size(); ++i)
    {
        if (mPlayers[i]->getScore() > maxScore) { maxScore = mPlayers[i]->getScore(); }
    }
    
    auto it = mPlayers.begin();

    while (it != mPlayers.end()) {
        if ((*it)->getScore() != maxScore) {
            it = mPlayers.erase(it);
        }
        else { ++it; }
    }

    //if there is 1 highScorer 
    if (mPlayers.size() == 1)
    {
        mEventCallback(Event::TournamentEnded);
        return;
    }

    //If there are more than one high scorer
    else
    {
        mEventCallback(Event::CantDetermineTheWinner);
        Play();
    }
}
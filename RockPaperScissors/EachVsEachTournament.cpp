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

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 1);

    std::shuffle(pairsOfPlayers.begin(), pairsOfPlayers.end(), gen);

    //Main cycle
    for (auto& pair : pairsOfPlayers)
    {
        if (dist(gen))
        {
            std::swap(pair.first, pair.second);
        }
        mPairOfCurrentRoundPlayers = pair;
        PlayRound();
    }

    //After tournament has been played  
    mEventCallback(Event::MainCycleEnded);

    int maxScore = mPlayers[0]->getScore();
    for (int i = 0; i < mPlayers.size(); ++i)
    {
        if (mPlayers[i]->getScore() > maxScore) { maxScore = mPlayers[i]->getScore(); }
    }

    for (int i = static_cast<int>(mPlayers.size()) - 1; i >= 0; --i)
    {
        if (mPlayers[i]->getScore() != maxScore) { mPlayers.erase(mPlayers.begin() + i); }
    }

    //if there is 1 highScorer 
    if (mPlayers.size() == 1)
    {
        mEventCallback(Event::TournamentEnded);
        return;
    }

    //if there are 2 highScorers
    if (mPlayers.size() == 2)
    {
        mPairOfCurrentRoundPlayers = PairOfPlayersSignature(mPlayers[0], mPlayers[1]);
        mEventCallback(Event::CantDetermineTheWinner);

        PlayRound();

        if (mPairOfCurrentRoundPlayers.first->getScore() > mPairOfCurrentRoundPlayers.second->getScore())
        {
            mPlayers.erase(mPlayers.end());
        }
        else { mPlayers.erase(mPlayers.begin()); }

        mEventCallback(Event::TournamentEnded);
        return;
    }

    //If there are more than two high scorer
    else
    {
        mEventCallback(Event::CantDetermineTheWinner);
        Play();
    }
}
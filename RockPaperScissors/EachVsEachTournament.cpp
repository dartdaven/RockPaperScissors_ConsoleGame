#include "EachVsEachTournament.h"

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
#include <windows.h>

void EachVsEachTournament::Play()
{
    //Random sorting but everyone will play with each other
    std::vector<PairOfPlayersSignature> pairsOfPlayers;
    pairsOfPlayers.reserve((players.size() * (players.size() - 1)) / 2);

    for (int i = 0; i < players.size(); ++i)
    {
        for (int j = i + 1; j < players.size(); ++j)
        {
            pairsOfPlayers.push_back({ players[i], players[j] });
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
        mPairOfPlayers = &pair;
        PlayRound(pair);
    }

    //After tournament has been played  
    tournamentEventCallback(Event::AllPlayersMadeMoves);

    int maxScore = players[0]->getScore();
    for (int i = 0; i < players.size(); ++i)
    {
        if (players[i]->getScore() > maxScore) { maxScore = players[i]->getScore(); }
    }

    for (int i = static_cast<int>(players.size()) - 1; i >= 0; --i)
    {
        if (players[i]->getScore() != maxScore) { players.erase(players.begin() + i); }
    }

    //if there is 1 highScorer 
    if (players.size() == 1)
    {
        tournamentEventCallback(Event::TournamentEnded);
        return;
    }

    //if there are 2 highScorers
    if (players.size() == 2)
    {
        PairOfPlayersSignature pairOfMaxScorers(players[0], players[1]);
        mPairOfPlayers = &pairOfMaxScorers;
        tournamentEventCallback(Event::TwoHighScorers);

        PlayRound(pairOfMaxScorers);

        if (pairOfMaxScorers.first->getScore() > pairOfMaxScorers.second->getScore())
        {
            players.erase(players.end());
        }
        else { players.erase(players.begin()); }

        tournamentEventCallback(Event::TournamentEnded);
        return;
    }

    //If there are more than two high scorer
    else
    {
        tournamentEventCallback(Event::CantDetermineTheWinner);
        Play();
    }
}
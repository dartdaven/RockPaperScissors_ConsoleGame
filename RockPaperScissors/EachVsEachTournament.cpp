#include "EachVsEachTournament.h"

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
#include <windows.h>

void EachVsEachTournament::Play()
{
    //Random sorting but everyone will play with each other
    std::vector<std::pair<int, int>> pairs;
    pairs.reserve((players.size() * (players.size() - 1)) / 2);

    for (int i = 0; i < players.size(); ++i)
    {
        for (int j = i + 1; j < players.size(); ++j)
        {
            pairs.push_back({i, j});
        }
    }
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 1);

    std::shuffle(pairs.begin(), pairs.end(), gen);

    //Main cycle
    for (auto& pair : pairs)
    {
        if (dist(gen))
        {
            std::swap(pair.first, pair.second);
        }
        PlayRound(pair.first, pair.second);
    }

    //After tournament has been played  
    int maxScore = players[0]->getScore();
    int maxScorerIndex{ 0 };
    int maxScoresAmount{ 0 };

    std::cout << "\nHere's the current standings of the tournament:\n";
    
    for (int i = 0; i < players.size(); ++i)
    {
        int tempScore = players[i]->getScore();
        
        std::cout << players[i]->getName() << " : " << tempScore << ";\n";
        
        if (tempScore > maxScore)
        {
            maxScore = tempScore;
            maxScoresAmount = 1;
            maxScorerIndex = i;
        }
        else if (tempScore == maxScore) { ++maxScoresAmount; }
    }

    if (maxScoresAmount == 1)
    {
        std::cout << "\nCongratulations to the " << players[maxScorerIndex]->getName() << ", the winner of the tournament\n";
        std::cin.get();
        return;
    }

    //if there are 2 highScorers
    std::vector<int> indexesOfMaxScorers;
    for (int i = 0; i < players.size(); ++i)
    {
        if (players[i]->getScore() == maxScore) { indexesOfMaxScorers.push_back(i); }
    }

    
    if (maxScoresAmount == 2)
    {
        std::cout << "\nWe have 2 guys with high score, but only one can be the winner\n";
        std::cout << "So it's the Duel then with rules of the tournament between " << players[indexesOfMaxScorers[0]]->getName() 
            << " and " << players[indexesOfMaxScorers[1]]->getName() << "\n";
        Sleep(5000);

        PlayRound(indexesOfMaxScorers[0], indexesOfMaxScorers[1]);
        
        if (players[indexesOfMaxScorers[0]]->getScore() > players[indexesOfMaxScorers[1]]->getScore())
        {
            std::cout << "\nCongratulations to the " << players[indexesOfMaxScorers[0]]->getName()
                << ", the winner of the tournament\n";
            std::cin.get();
            return;
        }
        else
        {
            std::cout << "\nCongratulations to the " << players[indexesOfMaxScorers[1]]->getName()
                << ", the winner of the tournament\n";
            std::cin.get();
            return;
        }

        return;
    }

    //If there are more than two high scorer
    else 
    {
        for (int i = (int)players.size() - 1; i >= 0; --i)
        {
            if (players[i]->getScore() != maxScore) { players.erase(players.begin() + i); }
        }

        std::cout << "\nCan't determine the winner\n";
        for (const auto& player : players)
        {
            std::cout << player->getName() << ", ";
        }
        std::cout << "will play the tournament again till the winner will be determined\n";

        //ask Alexey about recursion in this case
        Play();
    }
}

void EachVsEachTournament::ShowRulesAndScore()
{
    std::cout << "Game mode - Each vs Each, Rules - " << rulesToString(rules->getRules()) << ", Wins for Victory - " << wins4Victory << "\n";
    std::cout << rules->stringOfPossibleMoves() << "\n\n";
}
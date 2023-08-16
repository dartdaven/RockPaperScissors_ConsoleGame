#include "EachVsEachTournament.h"

#include <iostream>
#include <unordered_map>
#include <windows.h>

#include "enumMove.h"


void EachVsEachTournament::Play()
{
    //TEMPORARY DON't KNOW HOW TO DEAL 
    std::unordered_map<Move, std::string> movesToString
    {
        { Move::Rock, "Rock" },
        { Move::Paper, "Paper" },
        { Move::Scissors, "Scissors" },
        { Move::Lizard, "Lizard" },
        { Move::Spock, "Spock" }
    };

    //TO DO random sortin but everyone shoud play with each other
    for (int i = 0; i < players.size(); ++i)
    {
        for (int j = i + 1; j < players.size(); ++j)
        {

            int winsOfFirst{ 0 }, winsOfSecond{ 0 };

            while (winsOfFirst != wins4Victory && winsOfSecond != wins4Victory)
            {
                system("cls");
                ShowRulesAndScore();

                Move player1Result = players[i]->MakeMove(rules->rules());

                system("cls");
                ShowRulesAndScore();

                Move player2Result = players[j]->MakeMove(rules->rules());

                int tempResult = rules->determineWinner(player1Result, player2Result);

                switch (tempResult)
                {
                case 1:
                    std::cout << movesToString[player1Result] << " beats " << movesToString[player2Result] << std::endl;
                    ++winsOfFirst;
                    std::cout << players[i]->getName() << " won " << winsOfFirst << " of " << wins4Victory;
                    Sleep(3000);
                    break;
                case 2:
                    std::cout << movesToString[player2Result] << " beats " << movesToString[player1Result] << std::endl;
                    ++winsOfSecond;
                    std::cout << players[j]->getName() << " won " << winsOfSecond << " of " << wins4Victory;
                    Sleep(3000);
                    break;
                default:
                    std::cout << "It's the draw\n";
                    Sleep(3000);
                    break;
                }
            }

            if (winsOfFirst == wins4Victory)
            {
                std::cout << std::endl << "So, " << players[i]->getName() << " is the winner of this Round\n";
                players[i]->incrementScore();
            }
            else
            {
                std::cout << std::endl << "So, " << players[j]->getName() << " is the winner of this Round\n";
                players[j]->incrementScore();
            }
            Sleep(3000);
        }
    }

    std::cout << std::endl << "Here's the current standings of the tournament:\n";
    for (const auto& player : players)
    {
        std::cout << player->getName() << " : " << player->getScore() << ";\n";
    }

    //TO DO if there's similar results
}

void EachVsEachTournament::ShowRulesAndScore()
{
    std::string temp;
    if (rules->rules() == Rules::Classic) { temp = "Classic"; }
    else { temp = "BigBangTheory"; }

    std::cout << "Game mode - Each vs Each, Rules - " << temp << ", Wins for Victory - " << wins4Victory << "\n\n";
}

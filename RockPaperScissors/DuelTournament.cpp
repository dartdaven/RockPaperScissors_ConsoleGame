#include "DuelTournament.h"

#include <iostream>
#include <unordered_map>
#include <windows.h>

#include "enumMove.h"

void DuelTournament::Play()
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


    while (true)
    {
        system("cls");
        ShowRulesAndScore();

        Move player1Result = players[0]->MakeMove(rules->rules());

        system("cls");
        ShowRulesAndScore();

        Move player2Result = players[1]->MakeMove(rules->rules());

        system("cls");
        ShowRulesAndScore();
        
        std::cout << players[0]->getName() << " chose: " << movesToString[player1Result] << std::endl;
        std::cout << players[1]->getName() << " chose: " << movesToString[player2Result] << std::endl;

        int result = rules->determineWinner(player1Result, player2Result);

        switch (result)
        {
        case 1:
            std::cout << movesToString[player1Result] << " beats " << movesToString[player2Result] << std::endl;
            players[0]->incrementScore();
            std::cout << players[0]->getName() << " won\n";
            Sleep(3000);
            break;
        case 2:
            std::cout << movesToString[player2Result] << " beats " << movesToString[player1Result] << std::endl;
            players[1]->incrementScore();
            std::cout << players[1]->getName() << " won\n";
            Sleep(3000);
            break;
        default:
            std::cout << "It's the draw\n";
            Sleep(3000);
            break;
        }
    }
}

void DuelTournament::ShowRulesAndScore()
{
    //WARNING!!! HARD CODE
    std::string temp;
    if (rules->rules() == Rules::Classic) { temp = "Classic"; }
    else { temp = "BigBangTheory"; }

    std::cout << "Game mode - Duel, Rules - " << temp << std::endl;
    std::cout << players[0]->getName() << "'s score - " << players[0]->getScore() << "     " << players[1]->getName() << "'s score - " << players[1]->getScore() << "\n\n";
}

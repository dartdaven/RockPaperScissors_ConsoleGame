#include "SingleTournament.h"

#include <iostream>
#include <unordered_map>
#include <windows.h>

#include "enumMove.h"

void SingleTournament::Play()
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

        Move playerResult = players[0]->MakeMove(rules->rules());
        std::cout << "You chose: " << movesToString[playerResult] << std::endl;

        Move compResult = players[1]->MakeMove(rules->rules());
        std::cout << "Computer chooses: " << movesToString[compResult] << std::endl;

        int result = rules->determineWinner(playerResult, compResult);

        switch (result)
        {
        case 1:
            std::cout << movesToString[playerResult] << " beats " << movesToString[compResult] << std::endl;
            players[0]->incrementScore();
            std::cout << "You won\n";
            Sleep(3000);
            break;
        case 2:
            std::cout << movesToString[compResult] << " beats " << movesToString[playerResult] << std::endl;
            players[1]->incrementScore();
            std::cout << "Computer won\n";
            Sleep(3000);
            break;
        default:
            std::cout << "It's the draw\n";
            Sleep(3000);
            break;
        }
    }
}

void SingleTournament::ShowRulesAndScore()
{
    //WARNING!!! HARD CODE
    std::string temp;
    if (rules->rules() == Rules::Classic) { temp = "Classic"; }
    else { temp = "BigBangTheory"; }

    std::cout << "Game mode - Single, Rules - " << temp << std::endl;
    std::cout << "Your score - " << players[0]->getScore() << "     Computer's score - " << players[1]->getScore() << "\n\n";
}

#include "GameManager.h"

#include <iostream>
#include <unordered_map>
#include <windows.h>

#include "ClassicGameRules.h"
#include "BigBangGameRules.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

#include "enumMove.h"

void GameManager::start()
{
    //TO DO how many will Play?

    bool rulesHaveBeenChosen = false;

    GameRules* selectedRules = nullptr;

    ClassicGameRules classicGameRules;
    BigBangGameRules bigBangGameRules;

    HumanPlayer player;
    ComputerPlayer comp;

    do
    {
        int temp;
        
        std::cout << "Choose the rules: 1 - Classic, 2 - BigBangTheory: ";
        std::cin >> temp;

        if (temp == 1)
        {
            selectedRules = &classicGameRules;
            rulesHaveBeenChosen = true;
        }
        else if (temp == 2)
        {
            selectedRules = &bigBangGameRules;
            rulesHaveBeenChosen = true;
        }
        else
        {
            std::cout << "Incorrect input\n";
        }
    } while (!rulesHaveBeenChosen);


    //TEMPORARY
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
        Move playerResult = player.MakeMove(selectedRules->rules());
        std::cout << "You chose: " << movesToString[playerResult] << std::endl;
        
        Move compResult = comp.MakeMove(selectedRules->rules());
        std::cout << "Computer chooses: " << movesToString[compResult] << std::endl;

        int result = selectedRules->determineWinner(playerResult, compResult);
    
        switch (result)
        {
        case 1:
            std::cout << movesToString[playerResult] << " beats " << movesToString[compResult] << std::endl;
            std::cout << "You won\n";
            break;
        case 2:
            std::cout << movesToString[compResult] << " beats " << movesToString[playerResult] << std::endl;
            std::cout << "Computer won\n";
            break;
        default:
            std::cout << "It's the draw\n";
            break;
        }

        //system("cls");
    }
}

#include "SingleTournament.h"

#include <iostream>
#include <unordered_map>

#include "enumMove.h"

void SingleTournament::Play()
{
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
        Move playerResult = players[0]->MakeMove(rules->rules());
        std::cout << "You chose: " << movesToString[playerResult] << std::endl;

        Move compResult = players[1]->MakeMove(rules->rules());
        std::cout << "Computer chooses: " << movesToString[compResult] << std::endl;

        int result = rules->determineWinner(playerResult, compResult);

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
    }

}

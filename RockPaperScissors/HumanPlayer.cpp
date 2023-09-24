#include "HumanPlayer.h"

#include <iostream>
#include <limits>
#include <conio.h>

#include "GeneralUI.h"

Move HumanPlayer::makeMove(const std::unique_ptr<BaseGameRules>& rules) const
{
    GeneralUI::clearInputBuffer();

	int temp;

    std::cout << this->getName() << ", please make your move: ";
    
    while (true)
    {
        if (std::cin >> temp && temp >= 0 && temp < rules->getPossibleMoves().size()) { 
            return rules->getPossibleMoves()[temp];
        }
        else
        { 
            GeneralUI::incorrectInput();
        }
    }
}
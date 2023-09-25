#include "HumanPlayer.h"

#include <iostream>
#include <limits>
#include <conio.h>

#include "GeneralUI.h"

Move HumanPlayer::makeMove(const std::unique_ptr<BaseGameRules>& rules)
{
    GeneralUI::clearInputBuffer();

	int temp;

    std::cout << this->getName() << ", please make your move: ";
    
    while (true)
    {
        if (std::cin >> temp && temp >= 0 && temp < rules->getPossibleMoves().size()) 
        {
            mLastMoveMade = rules->getPossibleMoves()[temp];
            return mLastMoveMade;
        }
        else
        { 
            GeneralUI::incorrectInput();
        }
    }
}
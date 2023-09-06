#include "HumanPlayer.h"

#include <iostream>
#include <limits>

#include "GeneralUI.h"

Move HumanPlayer::makeMove(const std::unique_ptr<BaseGameRules>& rules) const
{
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

std::string HumanPlayer::getName() const
{
    return name;
}

bool HumanPlayer::isBot() const
{
    return false;
}

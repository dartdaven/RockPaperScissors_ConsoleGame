#include "HumanPlayer.h"

#include <iostream>
#include <limits>

int HumanPlayer::makeMove(const int& possibleMovesAmount) const
{
	int temp;
    
    while (true)
    {
        if (std::cin >> temp && temp >= 0 && temp < possibleMovesAmount) { return temp; }
        else
        { 
            std::cout << "Incorrect input. Try again: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

std::string HumanPlayer::getName() const
{
    return name;
}

#include "HumanPlayer.h"

#include <iostream>

Move HumanPlayer::MakeMove(const Rules& rules)
{
	int temp;

	switch (rules)
	{

	case Rules::BigBang:
		std::cout << name << ", please make your move. 0 - Rock, 1 - Paper, 2 - Scissors, 3 - Lizard, 4 - Spock: ";

		while (true)
        {
			if (std::cin >> temp && temp >= 0 && temp <= 4) { return static_cast<Move>(temp); }
            else { std::cout << "Incorrect input. Try again: "; }
        } 
	
	default:
		std::cout << name << ", please make your move. 0 - Rock, 1 - Paper, 2 - Scissors: ";
		
		while (true)
		{
			if (std::cin >> temp && temp >= 0 && temp <= 2) { return static_cast<Move>(temp); }
			else { std::cout << "Incorrect input. Try again: "; }
		}
	}
}

std::string HumanPlayer::getName()
{
    return name;
}

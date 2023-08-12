#include "HumanPlayer.h"

#include <iostream>

Move HumanPlayer::MakeMove(const Rules& rules)
{
	int temp;

	switch (rules)
	{

	case Rules::BigBang:
		std::cout << "Please make your move. 0 - Rock, 1 - Paper, 2 - Scissors, 3 - Lizard, 4 - Spock: ";
		std::cin >> temp;

		//TO DO check on correct input 
		
		return static_cast<Move>(temp);
	
	default:
		std::cout << "Please make your move. 0 - Rock, 1 - Paper, 2 - Scissors: ";
		std::cin >> temp;

		//TO DO check on correct input 

		return static_cast<Move>(temp);
	}
}

std::string HumanPlayer::getName()
{
    return name;
}

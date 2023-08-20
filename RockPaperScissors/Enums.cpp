#include "Enums.h"

#include <iostream>

std::string moveToString(const Move& move)
{
	switch (move)
	{
	case Move::Rock: return "Rock";
	case Move::Paper: return "Paper";
	case Move::Scissors: return "Scissors";
	case Move::Lizard: return "Lizard";
	case Move::Spock: return "Spock";
	default: 
		std::cerr << "Something wrong with converting Move to String\n";
		return std::string();
	}
}

std::string rulesToString(const Rules& rules)
{
	switch (rules)
	{
	case Rules::Classic: return "Classic";
	case Rules::BigBang: return "Big Bang Theory";
	default:
		std::cerr << "Something wrong with converting Rules to String\n";
		return std::string();
	}
}

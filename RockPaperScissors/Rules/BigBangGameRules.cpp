#include "BigBangGameRules.h"

#include <iostream>
#include <sstream>

BigBangGameRules::BigBangGameRules()
{
    possibleMoves = std::vector<Move>{ Move::Rock, Move::Paper, Move::Scissors, Move::Lizard, Move::Spock };
}

int BigBangGameRules::determineWinner(const std::pair<Move, Move>& pairOfMoves) const
{
    if (pairOfMoves.first == pairOfMoves.second) { return 0; }
    switch (pairOfMoves.first)
    {
    case Move::Rock:
        return (pairOfMoves.second == Move::Paper || pairOfMoves.second == Move::Spock) ? 2 : 1;
    case Move::Paper:
        return (pairOfMoves.second == Move::Scissors || pairOfMoves.second == Move::Lizard) ? 2 : 1;
    case Move::Scissors:
        return (pairOfMoves.second == Move::Rock || pairOfMoves.second == Move::Spock) ? 2 : 1;
    case Move::Lizard:
        return (pairOfMoves.second == Move::Rock || pairOfMoves.second == Move::Scissors) ? 2 : 1;
    case Move::Spock:
        return (pairOfMoves.second == Move::Paper || pairOfMoves.second == Move::Lizard) ? 2 : 1;
    default:
        std::cerr << "Something's wrong with the passed move, this round will not be counted\n";
        return 0;
    }
}

Rules BigBangGameRules::getRules() const
{
    return Rules::BigBang;
}
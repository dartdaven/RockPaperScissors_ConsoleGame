#include "ClassicGameRules.h"

#include <iostream>

ClassicGameRules::ClassicGameRules()
{
    possibleMoves = std::vector<Move>{ Move::Rock, Move::Paper, Move::Scissors };
}

int ClassicGameRules::determineWinner(const std::pair<Move, Move>& pairOfMoves) const
{
    if (pairOfMoves.first == pairOfMoves.second) { return 0; }

    switch (pairOfMoves.first)
    {
    case Move::Rock:
        return (pairOfMoves.second == Move::Paper) ? 2 : 1;
    case Move::Paper:
        return (pairOfMoves.second == Move::Scissors) ? 2 : 1;
    case Move::Scissors:
        return (pairOfMoves.second == Move::Rock) ? 2 : 1;
    default:
        std::cerr << "Something's wrong with the passed move, this round will not be counted\n";
        return 0;
    }
}

Rules ClassicGameRules::getRules() const
{
    return Rules::Classic;
}
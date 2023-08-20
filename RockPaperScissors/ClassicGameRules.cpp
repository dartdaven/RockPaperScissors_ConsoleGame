#include "ClassicGameRules.h"

#include <iostream>

ClassicGameRules::ClassicGameRules()
{
    possibleMoves = std::vector<Move>{ Move::Rock, Move::Paper, Move::Scissors };
}

int ClassicGameRules::determineWinner(const int& first, const int& second) const
{
    Move player1Move = possibleMoves[first];
    Move player2Move = possibleMoves[second];

    if (first == second) { return 0; }

    switch (player1Move)
    {
    case Move::Rock:
        return (player2Move == Move::Paper) ? 2 : 1;
    case Move::Paper:
        return (player2Move == Move::Scissors) ? 2 : 1;
    case Move::Scissors:
        return (player2Move == Move::Rock) ? 2 : 1;
    default:
        std::cerr << "Something's wrong with the passed move, this round will not be counted\n";
        return 0;
    }
}

Rules ClassicGameRules::getRules() const
{
    return Rules::Classic;
}
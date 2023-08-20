#include "BigBangGameRules.h"

#include <iostream>
#include <sstream>

BigBangGameRules::BigBangGameRules()
{
    possibleMoves = std::vector<Move>{ Move::Rock, Move::Paper, Move::Scissors, Move::Lizard, Move::Spock };
}

int BigBangGameRules::determineWinner(const int& first, const int& second) const
{
    Move player1Move = possibleMoves[first];
    Move player2Move = possibleMoves[second];

    if (first == second) { return 0; }
    switch (player1Move)
    {
    case Move::Rock:
        return (player2Move == Move::Paper || player2Move == Move::Spock) ? 2 : 1;
    case Move::Paper:
        return (player2Move == Move::Scissors || player2Move == Move::Lizard) ? 2 : 1;
    case Move::Scissors:
        return (player2Move == Move::Rock || player2Move == Move::Spock) ? 2 : 1;
    case Move::Lizard:
        return (player2Move == Move::Rock || player2Move == Move::Scissors) ? 2 : 1;
    case Move::Spock:
        return (player2Move == Move::Paper || player2Move == Move::Lizard) ? 2 : 1;
    default:
        std::cerr << "Something's wrong with the passed move, this round will not be counted\n";
        return 0;
    }
}

Rules BigBangGameRules::getRules() const
{
    return Rules::BigBang;
}
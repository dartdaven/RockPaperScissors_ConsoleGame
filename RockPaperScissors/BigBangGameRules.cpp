#include "BigBangGameRules.h"

int BigBangGameRules::determineWinner(Move first, Move second)
{
    if (first == second) { return 0; }
    switch (first)
    {
    case Move::Rock:
        return (second == Move::Paper || second == Move::Spock) ? 2 : 1;
    case Move::Paper:
        return (second == Move::Scissors || second == Move::Lizard) ? 2 : 1;
    case Move::Scissors:
        return (second == Move::Rock || second == Move::Spock) ? 2 : 1;
    case Move::Lizard:
        return (second == Move::Rock || second == Move::Scissors) ? 2 : 1;
    default:
        return (second == Move::Paper || second == Move::Lizard) ? 2 : 1;
    }
}

Rules BigBangGameRules::rules()
{
    return Rules::BigBang;
}

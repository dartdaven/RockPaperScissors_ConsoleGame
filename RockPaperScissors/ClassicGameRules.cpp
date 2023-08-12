#include "ClassicGameRules.h"

int ClassicGameRules::determineWinner(Move first, Move second)
{
    if (first == second) { return 0; }
    
    switch (first)
    {
    case Move::Rock:
        return (second == Move::Paper) ? 2 : 1;
    case Move::Paper:
        return (second == Move::Scissors) ? 2 : 1;
    default:
        return (second == Move::Rock) ? 2 : 1;
    }
}

Rules ClassicGameRules::rules()
{
    return Rules::Classic;
}


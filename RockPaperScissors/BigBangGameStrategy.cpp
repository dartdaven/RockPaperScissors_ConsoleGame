#include "BigBangGameStrategy.h"

int BigBangGameStrategy::determineWinner(int first, int second)
{
    if (first == second) { return 0; }
    switch (first)
    {
    case 0:
        return (second == 1 || second == 4) ? 2 : 1;
    case 1:
        return (second == 2 || second == 3) ? 2 : 1;
    case 2:
        return (second == 0 || second == 4) ? 2 : 1;
    case 3:
        return (second == 0 || second == 2) ? 2 : 1;
    default:
        return (second == 1 || second == 3) ? 2 : 1;
    }
}

int BigBangGameStrategy::type()
{
    return 1;
}

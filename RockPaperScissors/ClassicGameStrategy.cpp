#include "ClassicGameStrategy.h"

int ClassicGameStrategy::determineWinner(int first, int second)
{
    if (first == second) { return 0; }
    switch (first)
    {
    case 0:
        return (second == 1) ? 2 : 1;
    case 1:
        return (second == 2) ? 2 : 1;
    default:
        return (second == 0) ? 2 : 1;
    }

    //if (first == 0)
    //{
    //    return (second == 1) ? 2 : 1;
    //}
    //else if (first == 1)
    //{
    //    return (second == 2) ? 2 : 1;
    //}
    //else
    //{
    //    return (second == 0) ? 2 : 1;
    //}
}

int ClassicGameStrategy::type()
{
    return 0;
}

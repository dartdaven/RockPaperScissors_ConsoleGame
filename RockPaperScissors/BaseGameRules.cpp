#include "BaseGameRules.h"

#include <sstream>

int BaseGameRules::getAmountOfMoves() const
{
    return static_cast<int>(possibleMoves.size());
}

std::string BaseGameRules::stringOfPossibleMoves() const
{
    std::ostringstream oss;
    for (int i = 0; i < possibleMoves.size(); ++i)
    {
        if (i != possibleMoves.size() - 1)
        {
            oss << i << " - " << moveToString(possibleMoves[i]) << ", ";
        }
        else
        {
            oss << i << " - " << moveToString(possibleMoves[i]);
        }
    }

    return oss.str();
}

Move BaseGameRules::getMove(const int& integer) const
{
    return possibleMoves[integer];
}


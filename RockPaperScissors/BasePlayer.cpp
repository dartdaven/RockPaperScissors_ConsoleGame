#include "BasePlayer.h"

int BasePlayer::getScore() const
{
    return score;
}

void BasePlayer::resetScore()
{
    score = 0;
}

void BasePlayer::incrementScore()
{
    ++score;
}

void BasePlayer::setScore(const int& number)
{
    score = number;
}

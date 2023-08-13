#include "Player.h"

int Player::getScore()
{
    return score;
}

void Player::resetScore()
{
    score = 0;
}

void Player::incrementScore()
{
    ++score;
}

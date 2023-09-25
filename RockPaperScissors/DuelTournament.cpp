#include "DuelTournament.h"

#include <iostream>
#include <windows.h>

#include "Enums.h"

void DuelTournament::Play()
{
    mPairOfCurrentRoundPlayers = PairOfPlayersSignature{ mPlayers[0], mPlayers[1] };
    
    while (true)
    {
        PlayRound();
    }
}
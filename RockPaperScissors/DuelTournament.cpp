#include "DuelTournament.h"

#include <iostream>
#include <windows.h>

#include "Enums.h"

void DuelTournament::Play()
{
    PairOfPlayersSignature pairOfPlayers(players[0], players[1]);
    
    while (true)
    {
        PlayRound(pairOfPlayers);
    }
}
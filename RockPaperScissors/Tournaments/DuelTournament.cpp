#include "DuelTournament.h"

#include <iostream>
#include <windows.h>

#include "../Misc/Enums.h"

void DuelTournament::Play()
{
    mEventCallback(Event::TournamentStarted);

    mPairOfCurrentRoundPlayers = PairOfPlayersSignature{ mPlayers[0], mPlayers[1] };
    
    while (true)
    {
        PlayRound();
    }

    mEventCallback(Event::TournamentEnded);
}
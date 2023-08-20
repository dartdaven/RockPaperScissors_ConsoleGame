#include "DuelTournament.h"

#include <iostream>
#include <windows.h>

#include "Enums.h"

void DuelTournament::Play()
{
    while (true)
    {
        PlayRound(0, 1);
    }
}

void DuelTournament::ShowRulesAndScore()
{
    std::string temp = (players[1]->getName() == "Computer") ? "Game mode - Single, " : "Game mode - Duel, ";
    std::cout << temp << "Rules - " << rulesToString(rules->getRules()) << std::endl;
    std::cout << rules->stringOfPossibleMoves() << "\n\n";

    std::cout << players[0]->getName() << "'s score - " << players[0]->getScore() << "     " << players[1]->getName() << "'s score - " << players[1]->getScore() << "\n\n";
}

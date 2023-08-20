#include "BaseTournament.h"

#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>

void BaseTournament::PlayRound(int player1Index, int player2Index)
{
    int winsOfFirst{ 0 }, winsOfSecond{ 0 };

    while (winsOfFirst != wins4Victory && winsOfSecond != wins4Victory)
    {
        clearConsoleSmoothly();
        ShowRulesAndScore();

        if (players[player1Index]->getName() != "Computer")
        {
            std::cout << players[player1Index]->getName() << ", please make your move: ";
        }
        int player1Move = players[player1Index]->makeMove(rules->getAmountOfMoves());
        std::string player1MoveString = moveToString(rules->getMove(player1Move));

        clearConsoleSmoothly();
        ShowRulesAndScore();

        if (players[player2Index]->getName() != "Computer")
        {
            std::cout << players[player2Index]->getName() << ", please make your move: ";
        }
        int player2Move = players[player2Index]->makeMove(rules->getAmountOfMoves());
        std::string player2MoveString = moveToString(rules->getMove(player2Move));

        clearConsoleSmoothly();
        ShowRulesAndScore();

        std::cout << players[player1Index]->getName() << " chose " << player1MoveString << "     " 
            << players[player2Index]->getName() << " chose " << player2MoveString << "\n\n";
        Sleep(2000);

        int tempResult = rules->determineWinner(player1Move, player2Move);

        switch (tempResult)
        {
        case 1:
            std::cout << player1MoveString << " beats " << player2MoveString << std::endl;
            ++winsOfFirst;

            if (wins4Victory > 1)
            {
                std::cout << players[player1Index]->getName() << " won " << winsOfFirst << " of " << wins4Victory << std::endl;
                Sleep(3000);
            }

            break;
        case 2:
            std::cout << player2MoveString << " beats " << player1MoveString << std::endl;
            ++winsOfSecond;

            if (wins4Victory > 1)
            {
                std::cout << players[player2Index]->getName() << " won " << winsOfSecond << " of " << wins4Victory << std::endl;
                Sleep(3000);
            }

            break;
        default:
            std::cout << "It's the draw\n";
            Sleep(3000);
            break;
        }

    }

    if (winsOfFirst == wins4Victory)
    {
        std::cout << "So, " << players[player1Index]->getName() << " is the winner of this Round\n";
        players[player1Index]->incrementScore();
    }
    else
    {
        std::cout << "So, " << players[player2Index]->getName() << " is the winner of this Round\n";
        players[player2Index]->incrementScore();
    }
    Sleep(3000);
}

//From the internet
void BaseTournament::clearConsoleSmoothly()
{
    COORD topLeft = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    SetConsoleCursorPosition(console, topLeft);
}

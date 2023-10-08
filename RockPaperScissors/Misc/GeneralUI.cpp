#include "GeneralUI.h"

#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <limits>
#undef max

void GeneralUI::clearConsoleSmoothly()
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

void GeneralUI::clearInputBuffer()
{
    while (_kbhit()) { static_cast<void>(_getche()); }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void GeneralUI::incorrectInput()
{
    std::cerr << "Incorrect input. Try again: ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string GeneralUI::rulesToString(const Rules& rules)
{
    switch (rules)
    {
    case Rules::Classic: return "Classic";
    case Rules::BigBang: return "Big Bang Theory";
    default:
        std::cerr << "Something wrong with converting Rules to String\n";
        return std::string();
    };
}

std::string GeneralUI::moveToString(const Move& move)
{
    switch (move)
    {
    case Move::Rock: return "Rock";
    case Move::Paper: return "Paper";
    case Move::Scissors: return "Scissors";
    case Move::Lizard: return "Lizard";
    case Move::Spock: return "Spock";
    default:
        std::cerr << "Something wrong with converting Move to String\n";
        return std::string();
    };
}

std::string GeneralUI::tournamentTypeToString(const TournamentType& type)
{
    switch (type)
    {
    case TournamentType::EachVsEach: return "Each vs Each";
    case TournamentType::Mass: return "Massive";
    case TournamentType::Grid: return "Grid";
    case TournamentType::Duel: return "Duel";
    default:
        std::cerr << "Something wrong with converting Tournament type to String\n";
        return std::string();
    };
}

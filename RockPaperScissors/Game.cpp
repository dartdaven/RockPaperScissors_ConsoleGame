#include "Game.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

int Game::playRound(int first, int second)
{
    return strategy->determineWinner(first, second);
}

void Game::start()
{
    int first;
    int second;

    if (strategy->type())
    {
        std::cout << "Enter your choice (0 - Rock, 1 - Paper, 2 - Scissors, 3 - Lizard, 4 - Spock):";
        std::cin >> first;

        std::srand(std::time(nullptr));
        second = std::rand() % 5;
    }
    else
    {
        std::cout << "Enter your choice (0 - Rock, 1 - Paper, 2 - Scissors):";
        std::cin >> first;

        std::srand(std::time(nullptr));
        second = std::rand() % 3;
    }


    int result = playRound(first, second);

    std::cout << "Your choice: " << first << std::endl;
    std::cout << "Computer choise: " << second << std::endl;

    switch (result)
    {
    case 0:
        std::cout << "So it's the Draw" << std::endl;
        break;
    case 1:
        std::cout << "So you have won" << std::endl;
        break;
    case 2:
        std::cout << "Computer won" << std::endl;
        break;
    }
}

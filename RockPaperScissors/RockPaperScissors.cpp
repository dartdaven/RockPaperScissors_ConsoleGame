#include <iostream>

#include "GameManager.h"

int main()
{   
    std::cout << "Rock Paper Scissors Game\n";

    GameManager game;

    game.start();

    std::cin.get();
    return 0;
}

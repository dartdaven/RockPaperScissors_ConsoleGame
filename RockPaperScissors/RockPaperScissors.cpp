#include <iostream>

#include "GameStrategy.h"
#include "ClassicGameStrategy.h"
#include "BigBangGameStrategy.h"
#include "Game.h"

int main()
{
    int gameStrategy{ 0 };
    int playersAmount{ 0 };
    int typeOfTurnament{ 0 };
    int numberOfWins{ 0 };

    ClassicGameStrategy classicStrategy;
    BigBangGameStrategy bigBangStrategy;
    
    std::cout << "Rock Paper Scissors Game\n";
    std::cout << "Choose your rules: 1 - Classic, 2 - BigBang \n";
    
    std::cin >> gameStrategy;

    GameStrategy* selectedStrategy = nullptr;
    
    switch (gameStrategy)
    {
    case 1:
        std::cout << "Classic was chosen\n";
        selectedStrategy = &classicStrategy;
        break;
    case 2:
        std::cout << "BigBang was chosen\n";
        selectedStrategy = &bigBangStrategy;
        break;
    default:
        std::cout << "Strange input, so classic has been chosen\n";
        selectedStrategy = &classicStrategy;
        break;
    }

    Game game(selectedStrategy);

    while(true)
    {
        game.start();
    }

    std::cin.get();
    return 0;
}

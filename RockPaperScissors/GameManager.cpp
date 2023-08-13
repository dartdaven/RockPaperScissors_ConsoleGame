#include "GameManager.h"

#include <iostream>
#include <unordered_map>
#include <memory>
#include <windows.h>

#include "ClassicGameRules.h"
#include "BigBangGameRules.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Tournament.h"
#include "SingleTournament.h"

#include "enumMove.h"

void GameManager::start()
{
    std::unique_ptr<GameRules> selectedRules;
    
    bool rulesHaveBeenChosen = false;
    do
    {
        int temp;
        
        std::cout << "Choose the rules: 1 - Classic, 2 - BigBangTheory: ";
        std::cin >> temp;

        if (temp == 1)
        {
            selectedRules = std::make_unique<ClassicGameRules>();
            rulesHaveBeenChosen = true;
        }
        else if (temp == 2)
        {
            selectedRules = std::make_unique<BigBangGameRules>();
            rulesHaveBeenChosen = true;
        }
        else
        {
            std::cout << "Incorrect input\n";
        }
    } while (!rulesHaveBeenChosen);

    int wins4Victory{ 0 };
    std::cout << "How many wins are needed to finish the round: ";
    std::cin >> wins4Victory;
    //TO DO check for correct amount

    int playersAmount{ 0 };

    //ask Alexey if I can do it inside 
    std::vector<std::unique_ptr<Player>> players;

    bool playersAmountHasBeenChosen = false;
    do
    {
        std::cout << "How many players are going to play (10 max): ";
        std::cin >> playersAmount;

        if (playersAmount == 1)
        {
            players.push_back(std::make_unique<HumanPlayer>());
            players.push_back(std::make_unique<ComputerPlayer>());
            std::unique_ptr<Tournament> tournament = std::make_unique<SingleTournament>(std::move(players), std::move(selectedRules), wins4Victory);
            tournament->Play();
            playersAmountHasBeenChosen = true;
        }
        else if (playersAmount == 2)
        {
            playersAmountHasBeenChosen = true;
        }
        else if (playersAmount > 2 || playersAmount < 11)
        {
            playersAmountHasBeenChosen = true;
            std::cout << "What kind of tournament do you want: 1 - Each vs Each, 2 - Massive, 3 - Grid: ";
        }
        else
        {
            std::cout << "The game do not support THAT amount of players\n";
        }
    } while (!playersAmountHasBeenChosen);

}

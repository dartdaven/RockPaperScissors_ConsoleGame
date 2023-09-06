#include "GameManager.h"

#include <iostream>
#include <string>
#include <memory>
#include <limits>
#include <sstream>

#include "GeneralUI.h"
#include "DuelTournamentUI.h"
#include "EachVsEachTournamentUI.h"
#include "ClassicGameRules.h"
#include "BigBangGameRules.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "BaseTournament.h"
#include "DuelTournament.h"
#include "EachVsEachTournament.h"
#include "MassTournament.h"
#include "GridTournament.h"

#include "Enums.h"

void GameManager::start()
{   
    std::unique_ptr<BaseGameRules> selectedRules;
    std::vector<std::unique_ptr<BasePlayer>> players;
    std::unique_ptr<BaseTournament> tournament;
    std::unique_ptr<BaseTournamentUI> ui;

    //Chose the rules
    while (true)
    {
        int rulesInt;
        
        std::cout << "Choose the rules: 1 - Classic, 2 - BigBangTheory: ";
        std::cin >> rulesInt;

        if (rulesInt == 1)
        {
            selectedRules = std::make_unique<ClassicGameRules>();
            break;
        }
        else if (rulesInt == 2)
        {
            selectedRules = std::make_unique<BigBangGameRules>();
            break;
        }
        else
        {
            GeneralUI::incorrectInput();
        }
    }

    //Choose the game mode
    while (true)
    {
        int playersAmount;

        //Get amount of players
        while (true)
        {
            std::cout << "How many players are going to play (10 max): ";
            if (std::cin >> playersAmount && playersAmount >= 1 && playersAmount <= 10) { break; }
            else
            {
                std::cout << "The game do not support THAT amount of players\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }

        //Single player game mode
        if (playersAmount == 1)
        {
            players.push_back(std::make_unique<HumanPlayer>());
            players.push_back(std::make_unique<ComputerPlayer>());

            tournament = std::make_unique<DuelTournament>(std::move(players), std::move(selectedRules));
            ui = std::make_unique<DuelTournamentUI>(tournament);
            tournament->Play();
            
            break;
        }
        //Duel game mode
        else if (playersAmount == 2)
        {
            std::string input;
            
            std::cout << "First Player name: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, input);

            if (input.empty()) { players.push_back(std::make_unique<HumanPlayer>("Player 1")); }
            else { players.push_back(std::make_unique<HumanPlayer>(input)); }

            input.clear();

            std::cout << "Second Player name: ";
            std::cin.clear();
            std::getline(std::cin, input);

            if (input.empty()) { players.push_back(std::make_unique<HumanPlayer>("Player 2")); }
            else { players.push_back(std::make_unique<HumanPlayer>(input)); }

            tournament = std::make_unique<DuelTournament>(std::move(players), std::move(selectedRules));
            ui = std::make_unique<DuelTournamentUI>(tournament);
            tournament->Play();

            break;
        }
        //Choose the tournament 
        else
        {
            int tempTournament;

            while (true)
            {
                std::cout << "What kind of tournament do you want: 1 - Each vs Each, 2 - Massive, 3 - Grid: ";
                if (std::cin >> tempTournament && tempTournament >= 1 && tempTournament <= 3) { break; }
                else
                {
                    std::cout << "Incorrect input\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
            
            //Each vs Each
            if (tempTournament == 1)
            {
                int wins4Victory = getWins4Victory();

                players.reserve(playersAmount);

                for (int i = 0; i < playersAmount; ++i)
                {
                    //TO DO ask players name
                    std::ostringstream oss;
                    oss << "Player " << i + 1;

                    players.push_back(std::make_unique<HumanPlayer>(oss.str()));
                }

                tournament = std::make_unique<EachVsEachTournament>(std::move(players), std::move(selectedRules), wins4Victory);
                ui = std::make_unique<EachVsEachTournamentUI>(tournament);
                tournament->Play();
                break;
            }
            
            //Massive
            if (tempTournament == 2)
            {
                players.reserve(playersAmount);

                for (int i = 0; i < playersAmount; ++i)
                {
                    //TO DO ask players name
                    std::ostringstream oss;
                    oss << "Player " << i + 1;

                    players.push_back(std::make_unique<HumanPlayer>(oss.str()));
                }

                tournament = std::make_unique<MassTournament>(std::move(players), std::move(selectedRules));
                tournament->Play();
                break;
            }

            //Grid
            if (tempTournament == 3)
            {
                int wins4Victory = getWins4Victory();

                players.reserve(playersAmount);

                for (int i = 0; i < playersAmount; ++i)
                {
                    //TO DO ask players name
                    std::ostringstream oss;
                    oss << "Player " << i + 1;

                    players.push_back(std::make_unique<HumanPlayer>(oss.str()));
                }

                //TO DO normal
                if (playersAmount < 8)
                {
                    int compAmount = 8 - playersAmount;

                    for (int i = 0; i < compAmount; ++i)
                    {
                        players.push_back(std::make_unique<ComputerPlayer>());
                    }
                }

                tournament = std::make_unique<GridTournament>(std::move(players), std::move(selectedRules), wins4Victory);
                tournament->Play();
                break;
            }
        }
    }
}

int GameManager::getWins4Victory()
{
    while (true)
    {
        int wins4Victory{ 1 };
        std::cout << "How many wins are needed to complete the round (Range 1-5, 2 Recommended): ";
        if (std::cin >> wins4Victory && wins4Victory >= 1 && wins4Victory <= 5) { return wins4Victory; }
        else
        {
            GeneralUI::incorrectInput();
        }
    }
}

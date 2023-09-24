#include "GameManager.h"

#include <iostream>
#include <limits>
#include <string>

#include "GeneralUI.h"
#include "TournamentFactory.h"
#include "RulesFactory.h"

#include "ComputerPlayer.h"
#include "HumanPlayer.h"

#include "Enums.h"

void GameManager::start()
{   
    //Chose the rules
    Rules selectedRules{};
    int tempRulesInt{};
        
    std::cout << "Choose the rules: ";
    for (int i = 0; i < static_cast<int>(Rules::Count); i++)
    {
        if (i != static_cast<int>(Rules::Count) - 1)
        {
            std::cout << i + 1 << " - " << GeneralUI::rulesToString(static_cast<Rules>(i)) << ", ";
        }
        else
        {
            std::cout << i + 1 << " - " << GeneralUI::rulesToString(static_cast<Rules>(i)) << ": ";
        }

    }

    while (true)
    {
        if (std::cin >> tempRulesInt && tempRulesInt - 1 >= 0 && tempRulesInt - 1 < static_cast<int>(Rules::Count))
        {
            selectedRules = static_cast<Rules>(--tempRulesInt);
            break;
        }
        else
        {
            GeneralUI::incorrectInput();
        }
    }  

    //Choose the game mode
    int playersAmount;

    //Get amount of players
    while (true)
    {
        GeneralUI::clearInputBuffer();

        std::cout << "How many players are going to play (" << mMaxPlayersNumber << " max): ";
        if (std::cin >> playersAmount && playersAmount >= 1 && playersAmount <= mMaxPlayersNumber) { break; }
        else
        {
            std::cout << "The game do not support THAT amount of players\n";
        }
    }

    //Single player game mode
    if (playersAmount == 1)
    {
        mPlayersToMove.push_back(std::make_shared<HumanPlayer>());
        mPlayersToMove.push_back(std::make_shared<ComputerPlayer>());

        TournamentFactory::createTournamentWithUI(mTournament, mUI,
                                                  TournamentType::Duel, std::move(mPlayersToMove), selectedRules);
        mTournament->Play();
            
        return;
    }
    
    //Duel game mode
    else if (playersAmount == 2)
    {
        mPlayersToMove.reserve(playersAmount);
        setupPlayers();

        TournamentFactory::createTournamentWithUI(mTournament, mUI,
                                                  TournamentType::Duel, std::move(mPlayersToMove), selectedRules);
        mTournament->Play();

        return;
    }
    
    //Choose the tournament 
    else
    {
        int tempTournamentInt;

        std::cout << "What kind of tournament do you prefer: ";
        
        //Duel tournament should always be 0
        for (int i = 1; i < static_cast<int>(TournamentType::Count); i++)
        {
            if (i != static_cast<int>(TournamentType::Count) - 1)
            {
                std::cout << i << " - " << GeneralUI::tournamentTypeToString(static_cast<TournamentType>(i)) << ", ";
            }
            else
            {
                std::cout << i << " - " << GeneralUI::tournamentTypeToString(static_cast<TournamentType>(i)) << ": ";
            }
        }
        
        GeneralUI::clearInputBuffer();
        
        while (true)
        {

            if (std::cin >> tempTournamentInt && tempTournamentInt < 1 || tempTournamentInt > 3)
            {
                GeneralUI::incorrectInput();
                continue;
            }
            break;
        }

        TournamentType tournamentType = static_cast<TournamentType>(tempTournamentInt);
        int wins4Victory{};

        if (tournamentType != TournamentType::Mass) { wins4Victory = getWins4Victory(); }

        mPlayersToMove.reserve(playersAmount);
        setupPlayers();
        TournamentFactory::createTournamentWithUI(mTournament, mUI,
                                                    tournamentType, std::move(mPlayersToMove), selectedRules);
        mTournament->Play();
        return;
    }
}

int GameManager::getWins4Victory()
{
    std::cout << "How many wins are needed to complete the round (Range 1-5, 2 Recommended): ";
    GeneralUI::clearInputBuffer();

    while (true)
    {
        int wins4Victory{ 1 };
        if (std::cin >> wins4Victory && wins4Victory >= 1 && wins4Victory <= 5) { return wins4Victory; }
        else
        {
            GeneralUI::incorrectInput();
        }
    }
}

void GameManager::setupPlayers()
{
    std::cout << "\nPlease enter the players' names. " << mMaxPlayersNameSize << " characters max. Press Enter for default name.\n";
    
    GeneralUI::clearInputBuffer();
    
    for (int i = 0; i < mPlayersToMove.capacity(); ++i)
    {
        std::string input;

        std::cout << "Player's " << i + 1 << " name: ";
        std::getline(std::cin, input);
        std::cin.sync();
        std::cin.clear();
        

        if (input.empty()) { mPlayersToMove.push_back(std::make_unique<HumanPlayer>("Player " + std::to_string(i + 1))); }
        else if (input.size() > mMaxPlayersNameSize) 
        { 
            input.resize(mMaxPlayersNameSize);
            mPlayersToMove.push_back(std::make_unique<HumanPlayer>(input));
        }
        else { mPlayersToMove.push_back(std::make_unique<HumanPlayer>(input)); }
    }

    std::cin.putback('\n');
}

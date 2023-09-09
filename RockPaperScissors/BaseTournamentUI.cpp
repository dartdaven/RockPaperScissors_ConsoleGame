#include "BaseTournamentUI.h"

#include <sstream>
#include <Windows.h>

#include "GeneralUI.h"
#include "BaseTournament.h"

//for confetti
#include <thread>
#include <chrono>
#include <cstdlib>
#include <conio.h>

bool BaseTournamentUI::onEvent(const Event& event) const
{
    std::pair< std::shared_ptr<BasePlayer>, std::shared_ptr<BasePlayer>> pairOfRoundPlayers = tournament->getPairOfRoundPlayers();
    
    switch (event)
    {
    case Event::RoundStarted:
        GeneralUI::clearConsoleSmoothly();
        showRules();
        showScore();
        return true;

    case Event::PlayerMadeMove:
        GeneralUI::clearConsoleSmoothly();
        showRules();
        showScore();
        return true;

    case Event::AllPlayersMadeMoves:
        GeneralUI::clearConsoleSmoothly();
        showRules();
        showScore();

        {
            std::pair<Move, Move> pairOfMoves = tournament->getPairOfRoundMoves();

            std::cout << pairOfRoundPlayers.first->getName() << " chose " << moveToString(pairOfMoves.first) << "     "
                << pairOfRoundPlayers.second->getName() << " chose " << moveToString(pairOfMoves.second) << "\n\n";
            Sleep(2000);

            int tempResult = tournament->getRules()->determineWinner(pairOfMoves);

            switch (tempResult)
            {
            case 1:
                std::cout << moveToString(pairOfMoves.first) << " beats " << moveToString(pairOfMoves.second) << std::endl;

                if (tournament->getWins4Victory() > 1)
                {
                    std::cout << pairOfRoundPlayers.first->getName() << " won " << pairOfRoundPlayers.first->getWins() << " of " << tournament->getWins4Victory() << std::endl;
                }
                Sleep(3000);
                break;

            case 2:
                std::cout << moveToString(pairOfMoves.second) << " beats " << moveToString(pairOfMoves.first) << std::endl;

                if (tournament->getWins4Victory() > 1)
                {
                    std::cout << pairOfRoundPlayers.second->getName() << " won " << pairOfRoundPlayers.second->getWins() << " of " << tournament->getWins4Victory() << std::endl;
                }
                Sleep(3000);
                break;

            default:
                std::cout << "It's the draw\n";
                Sleep(3000);
                break;
            }
        }

        return true;

    case Event::RoundEnded:

        if (pairOfRoundPlayers.first->getWins() == tournament->getWins4Victory())
        {
            std::cout << pairOfRoundPlayers.first->getName() << " is the winner of the round\n";
            Sleep(3000);
        }
        else
        {
            std::cout << pairOfRoundPlayers.second->getName() << " is the winner of the round\n";
            Sleep(3000);
        }

        return true;
    }

    return false;
}

std::string BaseTournamentUI::rulesToString(const Rules& rules) const
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

std::string BaseTournamentUI::moveToString(const Move& move) const
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

std::string BaseTournamentUI::stringOfPossibleMoves(const std::vector<Move>& possibleMoves) const
{
    std::ostringstream oss;
    for (int i = 0; i < possibleMoves.size(); ++i)
    {
        if (i != possibleMoves.size() - 1)
        {
            oss << i << " - " << moveToString(possibleMoves[i]) << ", ";
        }
        else
        {
            oss << i << " - " << moveToString(possibleMoves[i]);
        }
    }

    return oss.str();
}

//not mine
void BaseTournamentUI::winnerOfTheTournament(const std::string& name) const
{
    int consoleWidth = 80; // Adjust this value based on your console width
    int consoleHeight = 24; // Adjust this value based on your console height
    std::string congratulations = "Congratulations to " + name;
    std::string secondLine = "The winner of the tournament";
    int congratsPosX = (consoleWidth - static_cast<int>(congratulations.length())) / 2;
    int congratsPosY = consoleHeight / 2;
    int secondLinePosX = (consoleWidth - static_cast<int>(secondLine.length())) / 2;
    int secondLinePosY = congratsPosY + 2; // Space between the lines

    // Clear the console
    system("cls");

    while (!_kbhit()) {
        // Create a buffer to store the animation state
        std::string buffer;
        for (int y = 0; y < consoleHeight; ++y) {
            for (int x = 0; x < consoleWidth; ++x) {
                if ((x >= congratsPosX && x < congratsPosX + congratulations.length()) &&
                    (y == congratsPosY)) {
                    buffer += congratulations[x - congratsPosX];
                }
                else if ((x >= secondLinePosX && x < secondLinePosX + secondLine.length()) &&
                    (y == secondLinePosY)) {
                    buffer += secondLine[x - secondLinePosX];
                }
                else {
                    if (rand() % 2 == 0) {
                        buffer += '*'; // You can use any character you like for confetti
                    }
                    else {
                        buffer += ' ';
                    }
                }
            }
            buffer += '\n';
        }

        // Output the buffer
        std::cout << buffer << std::flush;

        // Slow down the animation
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // Move the cursor to the top left corner (ANSI escape sequence)
        std::cout << "\x1B[H";
    }

    // Clear the console before exiting
    system("cls");
}
#pragma once

#include <string>

enum class Move { Rock, Paper, Scissors, Lizard, Spock };
enum class Rules { Classic, BigBang };

std::string moveToString(const Move& move);
std::string rulesToString(const Rules& rules);
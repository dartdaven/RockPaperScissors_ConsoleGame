#pragma once

#include "Enums.h"
#include "BaseGameRules.h"

class GeneralUI
{
public:
	static void clearConsoleSmoothly();
	static void clearInputBuffer();
	static void incorrectInput();
	static std::string rulesToString(const Rules& rules);
	static std::string moveToString(const Move& move);
	static std::string tournamentTypeToString(const TournamentType& move);
};


#pragma once

#include <memory>

#include "Enums.h"

#include "BaseTournamentUI.h"


class TournamentFactory
{
public:
	static void createTournamentWithUI( std::shared_ptr<BaseTournament>& outTournament,
										std::unique_ptr<BaseTournamentUI>& outUI,
										TournamentType tournamentType,
										std::vector<std::shared_ptr<BasePlayer>>&& players,
										Rules rulesType,
										int wins4Wictory = 1);

};


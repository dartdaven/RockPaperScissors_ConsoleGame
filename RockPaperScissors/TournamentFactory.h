#pragma once

#include <cassert>
#include <memory>

#include "Enums.h"

#include "BaseTournament.h"
#include "BaseTournamentUI.h"
#include "DuelTournament.h"
#include "DuelTournamentUI.h"
#include "EachVsEachTournament.h"
#include "EachVsEachTournamentUI.h"
#include "MassTournament.h"
#include "MassTournamentUI.h"
#include "GridTournament.h"
#include "GridTournamentUI.h"

class TournamentFactory
{
public:
	static void createTournamentWithUI( std::shared_ptr<BaseTournament>& outTournament,
										std::unique_ptr<BaseTournamentUI>& outUI,
										TournamentType tournamentType,
										std::vector<std::shared_ptr<BasePlayer>>&& players,
										Rules rulesType,
										int wins4Wictory = 1)
	{
		switch (tournamentType)
		{
		case TournamentType::Duel:
			outTournament = std::make_shared<DuelTournament>(std::move(players), rulesType, wins4Wictory);
			outUI = std::make_unique<DuelTournamentUI>(outTournament);
			break;

		case TournamentType::EachVsEach:
			outTournament = std::make_shared<EachVsEachTournament>(std::move(players), rulesType, wins4Wictory);
			outUI = std::make_unique<EachVsEachTournamentUI>(outTournament);
			break;

		case TournamentType::Mass:
			outTournament = std::make_shared<MassTournament>(std::move(players), rulesType, wins4Wictory);
			outUI = std::make_unique<MassTournamentUI>(outTournament);
			break;

		case TournamentType::Grid:
			outTournament = std::make_shared<GridTournament>(std::move(players), rulesType, wins4Wictory);
			outUI = std::make_unique<GridTournamentUI>(outTournament);
			break;

		default:
			assert(false);
		}
	}
};


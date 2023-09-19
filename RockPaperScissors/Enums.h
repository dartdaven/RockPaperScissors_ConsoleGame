#pragma once

enum class Move { Rock, Paper, Scissors, Lizard, Spock };

enum class Event { RoundStarted, PlayerMadeMove, AllPlayersMadeMoves, RoundEnded, 
	TournamentStarted, TournamentEnded, MainCycleEnded, TwoHighScorers, CantDetermineTheWinner, 
	CantDetermineLooser, GridRoundStarted, GridRoundEnded};
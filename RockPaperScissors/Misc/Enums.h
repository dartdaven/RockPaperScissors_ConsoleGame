#pragma once

enum class Move { Rock, Paper, Scissors, Lizard, Spock };

enum class TournamentType {

	Start,
	Duel = Start,
	MultiplayerTournamentsStart,
	EachVsEach = MultiplayerTournamentsStart,
	Mass,
	Grid,
	Count
};

enum class Event {
	RoundStarted, //Base, Grid
	PlayerMadeMove, // Base
	AllPlayersMadeMoves, //Base
	RoundEnded, //Base, Grid
	TournamentStarted, //Duel, EvE, Massive, Grid
	TournamentEnded, //Duel, EvE, Massive, Grid
	MainCycleEnded, //EvE, Massive, Grid
	CantDetermineTheWinner, //Eve, Massive
	CantDetermineLooser //Massive
}; 
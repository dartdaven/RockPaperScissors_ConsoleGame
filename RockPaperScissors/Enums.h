#pragma once

enum class Move { Rock, Paper, Scissors, Lizard, Spock };

enum class TournamentType { Duel, EachVsEach, Mass, Grid, Count };

enum class Event { RoundStarted, //Base, 
				   PlayerMadeMove, // Base,
				   AllPlayersMadeMoves, //Base,
				   RoundEnded, //Base,
				   TournamentStarted,
				   TournamentEnded, //Eve, Massive,Grid
				   MainCycleEnded, //EvE, Massive, Grid
				   TwoHighScorers, //Eve,
				   CantDetermineTheWinner, //Eve, Massive
				   CantDetermineLooser, //Massive
				   GridRoundStarted, //Grid
				   GridRoundEnded}; // Grid
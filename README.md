# RockPaperScissors_ConsoleGame
The objectives of this exercise are:
- Learn the basics of OOP and OOD
- Get familiarized with design patterns

## Original task
To develop a console game "Rock, Paper, Scissors" using OOP. There are two variants of the rules of the game: Classical and from the Big Bang Theory TV-Series. The possibility of a multi-person tournament with a configurable number of rounds and the determination of the winner at the end of the game is necessary. You also need to add the ability to play with the bot.

The program should be able to expand, be easily supported etc.

## My Design
First you have to choose the rules of the game.

Then the choice of championship depends on the number of players:
- If 1, endless game against the computer
- If 2, endless game against each other
- If there are more than two players, you can choose the championship

**Varieties of Tournaments:**
- Each VS Each
- Mass
- Grid

**Features:**
- If there are an odd number of players in the Grid Tournament, one of the players gets paired with a computer
- Animation showing who is currently playing with whom
- In the Each VS Each Tournament, the pairings are mixed, but everyone will still end up playing with everyone.
- Game logic classes are separated from UI classes.
- (NOT DONE YET) Simulation mode when 0 players are selected.
- (NOT DONE YET) Handle player input to start a new game or quit the game

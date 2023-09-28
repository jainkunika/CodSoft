# Tic-Tac-Toe Game

This is a C++ console application for playing a classic game of Tic-Tac-Toe. Two players, Player X and Player O, take turns marking spaces on a 3x3 grid to try to get three of their symbols in a row (horizontally, vertically, or diagonally). The game allows for continuous replay until the players decide to quit.

## How to Play

1. The game starts with an empty 3x3 grid.
2. Players take turns to enter the row and column where they want to place their symbol ('X' for Player X and 'O' for Player O).
3. The game will display the current state of the board after each move.
4. The game checks for a winner after each move, and if one player gets three symbols in a row, they win the game.
5. If the entire board is filled without a winner, the game ends in a draw.
6. After each game, you will have the option to replay or quit.

## Example Gameplay

Here's an example of how the gameplay might look:

```
Current board:
   |   |   
---------
   |   |   
---------
   |   |   

Player X, enter row (1-3) and column (1-3): 2 2

Current board:
   |   |   
---------
   | X |   
---------
   |   |   

Player O, enter row (1-3) and column (1-3): 1 1

Current board:
 O |   |   
---------
   | X |   
---------
   |   |   

...

Player X, enter row (1-3) and column (1-3): 1 3

Current board:
 O |   | X 
---------
   | X |   
---------
   | O |   

Player O, enter row (1-3) and column (1-3): 3 2

Current board:
 O |   | X 
---------
   | X |   
---------
   | O | O 

Player X wins!

Enter Y to replay, or any other key to quit: Y

...
```

## Features

- Two players (Player X and Player O) can play against each other.
- Continuous replay option after each game.
- Proper checks for valid moves, winning conditions, and draws.
- Display of the current state of the board after each move.


Enjoy playing Tic-Tac-Toe!

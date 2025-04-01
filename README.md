# Minesweeper Game in C

This is a simple console-based Minesweeper game implemented in C. The game randomly places mines on a 5x5 board, and the player must navigate the board without hitting a mine.

## Features
- 5x5 game board.
- Player selects the number of mines (1-24).
- Mines are randomly placed on the board.
- The game keeps track of previously entered positions to prevent duplicate inputs.
- The game ends when the player hits a mine or chooses to stop playing.

## How to Play
1. Run the program.
2. Enter the number of mines (1-24).
3. Choose a row and column (0-4) to reveal a cell.
4. If the cell contains a mine, you lose.
5. If the cell is safe, you can continue playing.
6. The game ends when you choose to stop or hit a mine.
7. At the end of the game, the board is revealed, showing mine placements.

## Compilation and Execution
To compile the program, use the following command:
```sh
gcc minesweeper.c -o minesweeper
```

To run the compiled program:
```sh
./minesweeper
```

## Example Gameplay
```
			 Welcome To Game
Here is the initial game board:
   0 | 1 | 2 | 3 | 4
  +---+---+---+---+---
0 | ~ | ~ | ~ | ~ | ~
  +---+---+---+---+---
...

How many mines do you want (1-24): 5
Enter row (0-4): 1
Enter column (0-4): 2
No mine here.
Do you want to continue (1 for yes, 0 for no)? 1
...
You hit a mine! You lose.
Game Over. Here is the matrix:
   | 0  | 1  | 2  | 3  | 4  |
--------------------------------
0 |  0  |  0  |  1  |  0  |  0  |
...
You Wins: 0

```
/*
 * Minesweeper Game in C
 * ----------------------
 * Author: Pavan Pandya
 * GitHub: https://github.com/PavanPandya016
 * 
 * Description:
 * A simple console-based Minesweeper game where the player must 
 * avoid hidden mines while selecting safe cells on a 5x5 grid.
 * 
 * License:
 * This project is open-source and free to use.
 */



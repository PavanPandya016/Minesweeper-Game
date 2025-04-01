/*
 * Minesweeper Game in C
 * Author: Pavan Pandya
 * GitHub: https://github.com/PavanPandya016
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define MAX_ATTEMPTS (SIZE * SIZE)

// Function to print the initial game board
void printTable() {
    printf("   ");
    for (int j = 0; j < SIZE; j++) {
        printf(" %d ", j);
    }
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf("  +");
        for (int j = 0; j < SIZE; j++) {
            printf("---+");
        }
        printf("\n%2d |", i);
        for (int j = 0; j < SIZE; j++) {
            printf(" ~ |"); // '~' represents an unrevealed cell
        }
        printf("\n");
    }
    printf("  +");
    for (int j = 0; j < SIZE; j++) {
        printf("---+");
    }
    printf("\n");
}

// Initialize the matrix with mines
void initializeMatrix(int matrix[SIZE][SIZE], int mines) {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < mines; i++) {
        int r, c;
        do {
            r = rand() % SIZE;
            c = rand() % SIZE;
        } while (matrix[r][c] == 1);
        matrix[r][c] = 1;
    }
}

// Function to get valid user input
int getValidInput(int min, int max, const char *prompt) {
    int input;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &input) == 1 && input >= min && input <= max) {
            break;
        }
        printf("Invalid input. Please enter a number between %d and %d.\n", min, max);
        while (getchar() != '\n');
    }
    return input;
}

int main() {
    int matrix[SIZE][SIZE];
    int previousInputs[MAX_ATTEMPTS][2];
    int attempts = 0, winCount = 0, hasLost = 0;
    
    printf("\t\t\t Welcome To Minesweeper!\n");
    printTable();
    int mines = getValidInput(1, SIZE * SIZE - 1, "How many mines do you want (1-24)? ");
    initializeMatrix(matrix, mines);
    
    while (1) {
        int row = getValidInput(0, SIZE - 1, "Enter row (0-4): ");
        int col = getValidInput(0, SIZE - 1, "Enter column (0-4): ");
        
        int duplicate = 0;
        for (int i = 0; i < attempts; i++) {
            if (previousInputs[i][0] == row && previousInputs[i][1] == col) {
                duplicate = 1;
                break;
            }
        }
        if (duplicate) {
            printf("You already selected this position. Try again.\n");
            continue;
        }
        
        previousInputs[attempts][0] = row;
        previousInputs[attempts][1] = col;
        attempts++;
        
        if (matrix[row][col] == 1) {
            printf("BOOM! You hit a mine! Game Over.\n");
            hasLost = 1;
            break;
        } else {
            printf("Safe move! No mine here.\n");
            winCount++;
        }
        
        int continueGame = getValidInput(0, 1, "Do you want to continue? (1 for Yes, 0 for No): ");
        if (continueGame == 0) break;
    }
    printf("Final Score: %d\n", hasLost ? 0 : winCount);
    return 0;
}

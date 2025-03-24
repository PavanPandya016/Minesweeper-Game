#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define MAX_ATTEMPTS SIZE * SIZE  // Maximum number of unique cells to be entered

void printTable() {
    printf("   ");
    for (int j = 0; j < SIZE; j++) {
        printf(" %d ", j);
        if (j < SIZE - 1) printf("|");
    }
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf("  +");
        for (int j = 0; j < SIZE; j++) {
            printf("---");
            if (j < SIZE - 1) printf("+");
        }
        printf("\n");

        printf("%d |", i);
        for (int j = 0; j < SIZE; j++) {
            printf(" ~ ");
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
    }

    printf("  +");
    for (int j = 0; j < SIZE; j++) {
        printf("---");
        if (j < SIZE - 1) printf("+");
    }
    printf("\n");
}

void initializeMatrix(int matrix[SIZE][SIZE], int mines) {
    // Initialize the matrix with 0s
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Place mines at random positions
    for (int i = 0; i < mines; i++) {
        int r, c;
        do {
            r = rand() % SIZE;
            c = rand() % SIZE;
        } while (matrix[r][c] == 1); // Ensure no duplicate mines
        matrix[r][c] = 1;
    }
}

int getValidInput(int min, int max, const char* prompt) {
    int input;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &input) != 1 || input < min || input > max) {
            printf("Invalid input. Please enter a number between %d and %d.\n", min, max);
            while (getchar() != '\n'); // Clear input buffer
        } else {
            break;
        }
    }
    return input;
}

void printMatrix(int matrix[SIZE][SIZE]) {
    // Print the top border of the matrix table with column numbers
    printf("\n   ");
    for (int j = 0; j < SIZE; j++) {
        printf("| %2d ", j);
    }
    printf("|\n");

    // Print the horizontal separator
    printf("   ");
    for (int j = 0; j < SIZE; j++) {
        printf("+----");
    }
    printf("+\n");

    // Print the rows with matrix values
    for (int i = 0; i < SIZE; i++) {
        printf(" %d ", i); // Print row number
        for (int j = 0; j < SIZE; j++) {
            printf("| %2d ", matrix[i][j]);
        }
        printf("|\n");

        // Print the horizontal separator after each row
        printf("   ");
        for (int j = 0; j < SIZE; j++) {
            printf("+----");
        }
        printf("+\n");
    }
}

int main() {
    int matrix[SIZE][SIZE];
    int mines;
    int row, col;
    int continueGame;
    int winCount = 0;  // Counter for safe moves
    int hasLost = 0;   // Flag to indicate if the user has lost

    // Store previous coordinates
    int previousInputs[MAX_ATTEMPTS][2];
    int attempts = 0;
    
    //print welcome
    printf("\t\t\t Welcome To Game\n");
    
    // Print the empty table
    printf("Here is the initial game board:\n");
    printTable();
	
    // Get number of mines
    mines = getValidInput(1, SIZE * SIZE - 1, "How many mines do you want (1-24): ");
    
    // Initialize matrix with mines
    initializeMatrix(matrix, mines);

    do {
        // Get user input for row and column in the range 0-4
        int validInput = 0;
        do {
            row = getValidInput(0, SIZE - 1, "Enter row (0-4): ");
            col = getValidInput(0, SIZE - 1, "Enter column (0-4): ");
            
            // Check if the input has been entered before
            int isDuplicate = 0;
            for (int i = 0; i < attempts; i++) {
                if (previousInputs[i][0] == row && previousInputs[i][1] == col) {
                    isDuplicate = 1;
                    break;
                }
            }

            if (isDuplicate) {
                printf("You have already entered this position. Please choose a different cell.\n");
            } else {
                previousInputs[attempts][0] = row;
                previousInputs[attempts][1] = col;
                attempts++;
                validInput = 1;
            }
        } while (!validInput);

        // Check the condition
        if (matrix[row][col] == 1) {
            printf("You hit a mine! You lose.\n");
            hasLost = 1; // Set loss flag
            break;       // Exit the loop
        } else {
            printf("No mine here.\n");
            winCount++; // Increment win count for safe moves
        }

        // Ask if the user wants to continue
        continueGame = getValidInput(0, 1, "Do you want to continue (1 for yes, 0 for no)? ");
        
        if (continueGame == 0) {
            // Print matrix when user decides to stop
            printf("Game Over. Here is the matrix:\n");
            printMatrix(matrix);
            break; // Exit the loop
        }

    } while (continueGame == 1);

    // Print the total number of wins or 0 if the user lost
    if (hasLost) {
        printf("You Wins: 0\n");
    } else {
        printf("You Wins: %d\n", winCount);
    }

    return 0;
}

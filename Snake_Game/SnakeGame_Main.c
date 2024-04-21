
#include "SnakeGame_Main.h"


/**
 * This code snippet represents the main function of a Snake game.
 * It initializes the game state, including variables for the snake's position, fruit position, score, and game over flag.
 * It handles user input to control the snake's movement and updates the game state accordingly.
 * The game logic includes updating the snake's position, checking for collisions, detecting when the snake eats the fruit, and ending the game if necessary.
 * The main loop repeatedly captures user input, updates the game state, and displays the game grid.
 * It also manages the snake's tail segments, adding new segments when the snake eats a fruit.
 * The game ends when the snake collides with the boundaries or itself, displaying a game-over message and the final score.
 * For more detailed code examples and resources, refer to Stack Overflow and GeeksforGeeks.
 * Good luck with your Snake game implementation!
 */

int main() {
    // This code snippet represents the main function of a Snake game.
    // It initializes the game state, including variables for the snake's position, fruit position, score, and game over flag.
    // The game handles user input to control the snake's movement and updates the game state accordingly.
    //
    // # Flow
    // 1. Initializes game state variables (snake's position, fruit position, score, and game over flag).
    // 2. Enters a while loop that continues until the game is started or over.
    // 3. Inside the while loop, it enters another while loop that continues until the user enters a valid direction.
    // 4. Renders the game grid, displays the score, and prompts the user to enter a direction.
    // 5. Captures the direction if a key is pressed and checks if it is valid.
    // 6. If the direction is valid, it sets the error flag to 0 and breaks out of the inner while loop.
    // 7. If the direction is invalid, it displays an error message and continues the inner while loop.
    // 8. Calls the `initializeGrid` function with the game state variables as arguments after the inner while loop.
    // 9. The outer while loop continues until the game is started or over.
    //
    // # Usage
    // This function serves as the main entry point for the Snake game, handling initialization, input, and game logic updates.

    SnakeHeadPosition snakehead = INITIAL_POSITION;
    SnakeHeadPosition previousHead = INITIAL_POSITION;
    FruitPosition fruit = INITIAL_POSITION;
    int score = 0;
    char direction;
    TailSegment tail[MAX_TAIL_LENGTH];
    int tailLength = 5;
    int GameStart = 1;
    int GameOver = 1;
    int err = 1;

    while (GameStart || GameOver) {
        // Update the previous head position with the current snake head position
        previousHead.x = snakehead.x;
        previousHead.y = snakehead.y;

        err = 1;
        while (err) {
            char** gameGrid = NULL;
            gameGrid = (char**)malloc(sizeof(char*) * GRID_SIZE);
            for (int i = 0; i < GRID_SIZE; i++) {
                gameGrid[i] = (char*)malloc(sizeof(char) * GRID_SIZE);
            }
            // Render the game grid before the input is captured to ensure smooth movement of the snake
            renderGrid(gameGrid);
            //renderTail(gameGrid, tail, tailLength); ***** crash the code if uncomment *****

            printf("Score: %d\n", score);
            printf("Enter direction (w/a/s/d): ");
            if (_kbhit()) {
                direction = _getch();
                switch (direction) {
                    case 's':
                    case 'w':
                    case 'd':
                    case 'a':
                        err = 0;
                        break;
                    default:
                        printf("Invalid direction. Please enter w, a, s, or d.\n");
                        break;
                }
            }
            // Update the tail before the grid is initialized
            updateTailPosition(tail, &tailLength,&previousHead);

            // Initialize the game grid
            initializeGrid(&GameStart, &fruit, &direction, &snakehead, &score);

            for (int i = 0; i < GRID_SIZE; i++) {
                free(gameGrid[i]);
            }
            free(gameGrid);
        }
    }
    return 0;
}


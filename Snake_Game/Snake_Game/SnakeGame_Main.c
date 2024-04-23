
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
    int score2tail = 0;
    char direction;
    int tailLength = 1;
    int GameStart = 1;
    int GameOver = 1;


    // Allocate memory for the tail array of TailSegment structs
    /*
    tailSeg:

    tailSeg is a pointer to a dynamically allocated array of TailSegment structs.
    In other words, tailSeg points to the memory block where the segments of the snake's tail are stored.
    Each element of this array (tailSeg[i]) represents one segment of the snake's tail.
    */
    TailSegment* tailSeg = NULL;
    /*
    tailGrid:

    tailGrid is a pointer to a dynamically allocated array of char pointers (char*).
    It represents a grid where each element can hold a character value.
    This grid is used to visualize the tail of the snake on the game board.
    Each element of tailGrid (tailGrid[i]) points to a dynamically allocated array of characters (char).
    Each array of characters represents one row of the grid where the snake's tail is displayed.
    */
    char** tailGrid = NULL;

    // 0.Allocate memory
    int allocationResult = allocateTail(&tailSeg, &tailGrid);
    if (allocationResult != 0) {
        return allocationResult; // Return the error code from the allocation function
    }

    while (GameStart || GameOver) 
    {
        // UI
        printf("Score: %d\n", score);
        printf("Enter direction (w/a/s/d): ");
        getValidDirection(&direction, &GameStart);

        // 1.Initializes the game grid by filling it with empty spaces. 
        initializeGrid(&GameStart);

        // 2.Handle Snake Head locations
        SnakeHead(&GameStart, &direction, &snakehead, &previousHead);

        // 3.Update the tail 
        /*
         *tailSeg is passed as a pointer to the array of tail segments, tailLength is passed as a pointer to the length of the tail, 
         *previousHead is passed as a pointer to the previous position of the snake's head. Inside the function, 
         *these parameters are used to manipulate the tail segments accordingly
        */
        updateTailPosition(tailSeg, &tailLength,&previousHead, &score2tail);
        //You're passing the tail array to the updateTailPosition function as the first argument. Since tail is a pointer to a
        //TailSegment struct, this is correct. The function expects a pointer to the beginning of the TailSegment array, which
        //is exactly what you're providing.
        

        // 4.Handle fruit locations
       score2tail =(updateFruitPosition(&snakehead, &GameStart, &fruit, &score));
        // 5.Render the game grid 
        renderGrid();

        // Game Over Detector
        if(checkTailCollision(tailSeg, &tailLength, &snakehead))
        {
            printf(" GameOver");
            GameOver = 0;
        }

        }
        // 0.Deallocate memory when done
        deallocateTail(tailSeg, tailGrid);
    return 0;
}


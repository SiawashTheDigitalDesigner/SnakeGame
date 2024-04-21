# include "Grid.h"
// Function to render the game grid
/**
 * Function to render the game grid.
 * 
 * This function renders the game grid by printing the characters stored in the gameGrid array.
 * It clears the console screen before printing the grid, and adds a delay of 250 milliseconds.
 * The rendering is platform-dependent, with different commands used for Windows and Unix-based systems.
 * 
 * Parameters:
 * None
 * 
 * Returns:
 * None
 */
void renderGrid() {
    usleep(250000);
    #ifdef _WIN32
        system("cls"); // For Windows
    #else
        printf("\033[H\033[J"); // For Unix-based systems
    #endif
    for (int y = 0; y < GAME_HEIGHT; y++) {
        for (int x = 0; x < GAME_WIDTH; x++) {
            putchar(gameGrid[y][x]);
            putchar(' ');
        }
        putchar('\n');
    }
}
#include "../fruit/FruitPosition.h"
# include "Grid.h"
// Function to initialize the game grid
/**
 * Initializes the game grid by filling it with empty spaces. 
 * 
 * @param GameStart - A pointer to the game start variable.
 */
void initializeGrid(int* GameStart) {
    // Fill the grid with empty spaces
    for (int y = 0; y < GAME_HEIGHT; y++) {
        for (int x = 0; x < GAME_WIDTH; x++) {
            gameGrid[y][x] = EMPTY_SPACE;
        }
    }


}

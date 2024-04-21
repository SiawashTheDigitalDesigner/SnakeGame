#include "../fruit/FruitPosition.h"
# include "Grid.h"
#include "../snake/SnakeHeadPosition.h"
// Function to initialize the game grid
/**
 * Initializes the game grid by filling it with empty spaces. 
 * Places the snake's head at a starting position and the fruit at a random starting position.
 * 
 * @param GameStart - A pointer to the game start variable.
 * @param fruit - A pointer to the fruit position variable.
 * @param direction - A pointer to the direction variable.
 * @param snakehead - A pointer to the snake's head position variable.
 * @param score - A pointer to the score variable.
 */
void initializeGrid(int* GameStart, FruitPosition* fruit, char* direction, SnakeHeadPosition* snakehead, int* score) {
    // Fill the grid with empty spaces
    for (int y = 0; y < GAME_HEIGHT; y++) {
        for (int x = 0; x < GAME_WIDTH; x++) {
            gameGrid[y][x] = EMPTY_SPACE;
        }
    }

    // Place the snake's head at a starting position
    SnakeHead(GameStart, direction, snakehead);

    // Place the fruit at a starting position
    updateFruitPosition(snakehead, GameStart, fruit, score);
}

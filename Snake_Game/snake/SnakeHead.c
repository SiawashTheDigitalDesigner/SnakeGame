
#include "../snake/SnakeHeadPosition.h"
#include "../Grid/Grid.h"
/**
 * SnakeHead function updates the position of the snake's head based on the game state and user input.
 * 
 * Parameters:
 * - GameStart: A pointer to an integer indicating whether the game has started or not.
 * - direction: A pointer to a character indicating the direction of movement for the snake's head.
 * - snakehead: A pointer to a SnakeHeadPosition struct representing the current position of the snake's head.
 * 
 * Returns: None
 */
void SnakeHead(int* GameStart, char* direction, SnakeHeadPosition* snakehead) {
    if (*GameStart)
    {
        snakehead->y = GAME_HEIGHT/2;
        snakehead->x = GAME_WIDTH/2;
    }
    else
    {
        switch (*direction) 
            {
            case 's':
                snakehead->y++;
                break;
            case 'w':
                snakehead->y--;
                break;
            case 'd':
                snakehead->x++;
                break;
            case 'a':
                snakehead->x--;
                break;
            default:
                break;
            }   
    }

    // Check if snakehead coordinates are within bounds
    if (snakehead->x < 0 || snakehead->x >= GAME_WIDTH || snakehead->y < 0 || snakehead->y >= GAME_HEIGHT) {
        // Handle out of bounds error (e.g., wrap around or game over)
        // Example: Wrap around to the opposite side of the grid
        snakehead->x = (snakehead->x + GAME_WIDTH) % GAME_WIDTH;
        snakehead->y = (snakehead->y + GAME_HEIGHT) % GAME_HEIGHT;
    }

    UpdateGameGrid(snakehead);
}

void UpdateGameGrid(SnakeHeadPosition* snakehead) {
    // Update gameGrid with snake head position
    gameGrid[snakehead->y][snakehead->x] = SNAKE_HEAD;
}


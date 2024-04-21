#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

/**
 * This code snippet defines a grid for a game. It includes constants for the game width and height, 
 * as well as symbols to represent different elements on the grid such as empty space, snake body, 
 * snake head, and fruit. The game grid itself is a 2D character array. This code snippet is intended 
 * to be included in a larger C program for implementing a game.
 */

// Game width and height
#define GAME_WIDTH  10
#define GAME_HEIGHT 10
#define GRID_SIZE GAME_WIDTH * GAME_HEIGHT // Add GRID_SIZE here

// Define symbols to represent grid elements
#define EMPTY_SPACE '.'
#define SNAKE_BODY '*'
#define SNAKE_HEAD '@'
#define FRUIT 'F'

// Define the game grid
char gameGrid[GAME_HEIGHT][GAME_WIDTH];


#endif // GRID

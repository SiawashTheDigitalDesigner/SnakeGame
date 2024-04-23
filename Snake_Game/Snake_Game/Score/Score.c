#include "../snake/SnakeHeadPosition.h"
#include "../fruit/FruitPosition.h"
/**
 * Function: Score
 * ----------------
 * Checks if the snake's head and the fruit have the same coordinates.
 *
 * snakeHead: Pointer to the SnakeHeadPosition struct representing the snake's head position.
 * fruit: Pointer to the FruitPosition struct representing the fruit position.
 * score: Pointer to the integer variable representing the score.
 *
 * Returns:
 * 1 if collision occurred, 0 otherwise.
 */
int Score(SnakeHeadPosition* snakeHead, FruitPosition* fruit, int* score) {
    // Check if the snake's head and the fruit have the same coordinates
    if (snakeHead->x == fruit->y && snakeHead->y == fruit->x) {
        (*score)++;
        return 1; // Collision occurred
    } else {
        return 0; // No collision
    }
}


/*
main code test :
    if (Score(&snake,&fruit)) {
        score++;
        printf("Collision occurred! Score: %d\n", score);
    } else {
        printf("No collision. Score: %d\n", score);
    }

*/

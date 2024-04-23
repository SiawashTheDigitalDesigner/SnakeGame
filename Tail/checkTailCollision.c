#include "../Tail/TailSegment.h"
#include "../snake/SnakeHeadPosition.h"
// Function to check for collision with the tail
/**
 * Checks for collision between the snake's head and its tail segments.
 *
 * @param tail A pointer to an array of `TailSegment` structures representing the snake's tail segments.
 * @param tailLength A pointer to an integer representing the length of the snake's tail.
 * @param snakehead A pointer to a `SnakeHeadPosition` structure representing the position of the snake's head.
 * @return 1 if a collision between the snake's head and its tail segments is detected, 0 otherwise.
 */
int checkTailCollision(TailSegment *tail, int* tailLength, SnakeHeadPosition* snakehead) {
    // Check for collision with tail segments
    for (int i = 0; i < (*tailLength); i++) {
        if (snakehead->x == tail[i].x && snakehead->y == tail[i].y) {
            // access to member of array structure via pointer  == .
            // access to member of structure via pointer        == ->
            return 1; // Collision detected
        }
    }
    return 0; // No collision
}
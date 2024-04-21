#include "../Tail/TailSegment.h"
#include "../snake/SnakeHeadPosition.h"
/**
 * Update the position of the tail segments based on the previous head position.
 *
 * @param tail The array of tail segments.
 * @param tailLength The length of the tail array.
 * @param previousHead The previous position of the snake's head.
 */
void updateTailPosition(TailSegment *tail, int *tailLength, SnakeHeadPosition *previousHead) {
    // Move the tail segments
    // Start from the end of the tail array and move each segment one position towards the head
    for (int i = *tailLength - 1; i > 0; i--) {
        tail[i] = tail[i - 1]; // Move the tail segment at index i-1 to index i
    }
    /// Add a new tail segment at the previous position of the snake's head
    // Assign the x and y coordinates of the first tail segment to the previous position of the snake's head
    tail[0].x = previousHead->x;
    tail[0].y = previousHead->y;
}
#include "../Tail/TailSegment.h"
#include "../snake/SnakeHeadPosition.h"
/**
 * Update the position of the tail segments based on the previous head position.
 *
 * @param tail An array of TailSegment structs representing the segments of the snake's tail.
 * @param tailLength The length of the tail array.
 * @param previousHead A pointer to a SnakeHeadPosition struct representing the previous position of the snake's head.
 */
void updateTailPosition(TailSegment *tail, int *tailLength, SnakeHeadPosition *previousHead, int* score2tail) {

    /// Add a new tail segment at the previous position of the snake's head
    // Assign the x and y coordinates of the first tail segment to the previous position of the snake's head
    /*
    *After moving the existing tail segments, the function assigns the coordinates of the previous
     head of the snake to the first tail segment (tail[0]).
    *This effectively adds a new tail segment at the previous position of the snake's head.
    */
    tail[0].x = previousHead->x;
    tail[0].y = previousHead->y;
   // decide for last tail segmant based of score
    (*tailLength) = (*tailLength) + (*score2tail);
    /* move the rest of tail:
    *The function starts by iterating over the tail segments from the end (*tailLength - 1) to the second segment (i > 0).
    *For each segment at index i, it copies the coordinates of the segment at index i-1 to the segment at index i.
     This effectively moves each segment one position towards the head of the snake.
    *This loop ensures that each tail segment follows the one in front of it, effectively mimicking the movement of the snake's tail.
    */
    for (int i = (*tailLength) - 1; i > 0; i--) {
        tail[i].x = tail[i - 1].x;
        tail[i].y = tail[i - 1].y;
    }

    // render tail on Grid
    renderTail(tail, tailLength);


}

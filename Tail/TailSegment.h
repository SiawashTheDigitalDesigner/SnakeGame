#ifndef TAIL_H_INCLUDED
#define TAIL_H_INCLUDED
/*
TailSegment:

    TailSegment is a user-defined struct type.
    It represents a segment of the snake's tail in a game.
    Each TailSegment consists of two integer fields: x and y, 
    representing the coordinates of the segment on a grid.
*/
typedef struct {
    int x;
    int y;
} TailSegment;

#define MAX_TAIL_LENGTH 50 // Adjust the maximum length as needed



#endif // TAIL
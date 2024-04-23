#include "../Tail/TailSegment.h"
#include "../Grid/Grid.h"
// Function to render the tail
/**
 * Renders the tail segments on the game grid.
 *
 * @param gameGrid The game grid represented as a 2D character array.
 * @param tail The array of tail segments.
 * @param tailLength The length of the tail.
 */
void renderTail(TailSegment* tail, int* tailLength) {
        // Iterate over the tail segments
        for (int i = 0; i < (*tailLength); i++) {
            // Set the SNAKE_BODY symbol in the gameGrid array at the coordinates of the tail segment
            // Note: 'tail' is an array of TailSegment structs, not a pointer.
            //       Therefore, we access its members using the . operator, not the -> operator.
            gameGrid[tail[i].y][tail[i].x] = SNAKE_BODY;
        }
}
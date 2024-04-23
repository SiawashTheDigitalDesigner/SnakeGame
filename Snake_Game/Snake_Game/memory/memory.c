#include <stdio.h>
#include <stdlib.h> // dynamic allocate memory
#include "../Tail/TailSegment.h"

/*
Memory Allocation:

    Memory for tailSeg is allocated using malloc to create an array of TailSegment structs with a size of MAX_TAIL_LENGTH.
    Memory for tailGrid is allocated similarly using malloc to create an array of char* with a size of MAX_TAIL_LENGTH.
    Additionally, memory for each row of tailGrid is allocated individually using malloc inside a loop, creating arrays of 
    characters with a size of MAX_TAIL_LENGTH for each row.

    In summary, tailSeg holds the data representing the segments of the snake's tail, while tailGrid provides a grid-based 
    visualization of the tail segments on the game board. Both are dynamically allocated to accommodate a maximum number of 
    tail segments and allow for flexible memory management.
*/

int allocateTail(TailSegment** tail, char*** tailGrid) {
    // Allocate memory for the tail array of TailSegment structs
    *tail = (TailSegment*)malloc(sizeof(TailSegment) * MAX_TAIL_LENGTH);
    if (*tail == NULL) {
        fprintf(stderr, "Memory allocation for tailSegments failed\n");
        return 1; // Return non-zero to indicate failure
    }

    // Allocate memory for the tail array of char pointers
    *tailGrid = (char**)malloc(sizeof(char*) * MAX_TAIL_LENGTH);
    if (*tailGrid == NULL) {
        fprintf(stderr, "Memory allocation for tailGrid failed\n");
        free(*tail); // Free previously allocated memory
        return 1; // Return non-zero to indicate failure
    }

    for (int i = 0; i < MAX_TAIL_LENGTH; i++) {
        (*tailGrid)[i] = (char*)malloc(sizeof(char) * MAX_TAIL_LENGTH);
        if ((*tailGrid)[i] == NULL) {
            fprintf(stderr, "Memory allocation for tailGrid[%d] failed\n", i);
            // Free previously allocated memory
            for (int j = 0; j < i; j++) {
                free((*tailGrid)[j]);
            }
            free(*tailGrid);
            free(*tail);
            return 1; // Return non-zero to indicate failure
        }
    }

    return 0; // Successful allocation
}



void deallocateTail(TailSegment* tail, char** tailGrid) {
    // Free the allocated memory for tailGrid
    for (int i = 0; i < MAX_TAIL_LENGTH; i++) {
        free(tailGrid[i]);
    }
    free(tailGrid);

    // Free the allocated memory for tail
    free(tail);
}
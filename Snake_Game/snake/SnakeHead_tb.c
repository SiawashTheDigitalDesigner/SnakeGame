// Define the SnakePosition struct and SnakeHead function here...

#include "../snake/SnakeHeadPosition.h"
//test file ("tst.c") is located in a subfolder within your main project folder, and the header file ("coordinate.h") is
// located in the main project folder
// use relative paths in your "#include../" directive to specify the path to the header file relative to the
// location of the source file
/**
 * Function: test_SnakeHead_movement
 * -------------------------------
 * This function is used to test the movement of the snake's head. It takes a pointer to a SnakeHeadPosition structure as a parameter.
 * The function prints the initial position of the snake's head and then tests moving the snake in different directions (up, right, down, left).
 * After each movement, the function prints the new position of the snake's head.
 */
void test_SnakeHead_movement(SnakeHeadPosition *snake) {
    //In the test_snake_movement function, you're trying to access structure members using the dot operator (.)
    // instead of the arrow operator (->) because you're dealing with a pointer to a structure.

    printf("Initial position: (%d, %d)\n", snake->y, snake->x);

    // Test moving the snake up
    SnakeHead('u', snake);
    printf("After moving up: (%d, %d)\n", snake->y, snake->x);

    // Test moving the snake right
    SnakeHead('r', snake);
    printf("After moving right: (%d, %d)\n", snake->y, snake->x);

    // Test moving the snake down
    SnakeHead('d', snake);
    printf("After moving down: (%d, %d)\n", snake->y, snake->x);

    // Test moving the snake left
    SnakeHead('l', snake);
    printf("After moving left: (%d, %d)\n", snake->y, snake->x);
}


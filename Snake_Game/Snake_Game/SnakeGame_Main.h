#ifndef SNAKE_LIB_H_INCLUDED
#define SNAKE_LIB_H_INCLUDED
/**
 * This code snippet is a header file for a C library called "snake_lib".
 * It includes several other header files and defines some constants.
 * The library provides functions for controlling a snake game, such as updating the snake's position,
 * updating the fruit's position, initializing the game grid, rendering the grid, updating the tail's position,
 * and rendering the tail.
 * The library also includes a test function for snake movement.
 * The code snippet is intended to be included in a larger C program that implements a snake game.
 */
// base library
#include <stdio.h> // for input/output and potentially // rand()

//#include <conio.h> // Include conio.h for Windows
//#include <curses.h>
// dev libary
#include "snake/SnakeHeadPosition.h"
#include "fruit/FruitPosition.h"
#include "Grid/Grid.h"
#include "Tail/TailSegment.h"
// define
// In C, you cannot directly initialize variables before the program starts running. C doesn't have a
// built-in mechanism for initializing variables at the global scope before program execution.
// In C++, you have more flexibility in initializing variables before program execution compared to C. C++
// allows you to define and initialize variables at file scope, which means they are initialized before the
// program starts running.
#define INITIAL_POSITION {GAME_WIDTH/2, GAME_HEIGHT/2} // Start the snake at position (0, 0)



// functions declaration
// 0.memory
int allocateTail(TailSegment** tail, char*** tailGrid);
void deallocateTail(TailSegment* tail, char** tailGrid);

//1.init grid with .
void initializeGrid(int* GameStart);
// UI
void getValidDirection(char* direction, int* GameStart);

// 2.snake head
void SnakeHead(int* GameStart, char* direction, SnakeHeadPosition* snakehead, SnakeHeadPosition* previousHead);
//void test_snake_movement(SnakeHeadPosition *snake); // tb

//3.tail
void updateTailPosition(TailSegment *tail, int *tailLength, SnakeHeadPosition *previousHead, int* score2tail);
void renderTail(TailSegment* tail, int* tailLength);
int checkTailCollision(TailSegment *tail, int* tailLength, SnakeHeadPosition* snakehead);
// 4.fruit
int updateFruitPosition(SnakeHeadPosition* snakeHead,int* GameStart, FruitPosition* fruit, int* score);
int Score(SnakeHeadPosition* snakeHead, FruitPosition* fruit, int* score);

// 5.render
void renderGrid();
#endif // SNAKE_LIB_H_INCLUDED

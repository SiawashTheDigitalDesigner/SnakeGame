#ifndef COORDINATE_H_INCLUDED
#define COORDINATE_H_INCLUDED
/**
 * @file coordinate.h
 * @brief Header file for the Coordinate module.
 *
 * This header file defines the SnakeHeadPosition struct, which represents the coordinates of the snake's head.
 * The struct contains two integer fields: y for the y-coordinate and x for the x-coordinate.
 * This module is used to handle coordinate operations in a snake game.
 */
// types
typedef struct {
    int y; // y-coordinate
    int x; // x-coordinate
} SnakeHeadPosition;


void UpdateGameGrid(SnakeHeadPosition* snakehead);
#endif // COORDINATE_H_INCLUDED

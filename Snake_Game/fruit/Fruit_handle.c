#include "../fruit/FruitPosition.h"
# include "../Grid/Grid.h"
#include "../snake/SnakeHeadPosition.h"
// Function to initialize the fruit position randomly within the game boundaries
// Function to update the fruit position randomly within the game boundaries
/**
 * Function to update the fruit position randomly within the game boundaries.
 *
 * @param snakeHead Pointer to the SnakeHeadPosition struct.
 * @param GameStart Pointer to the GameStart variable.
 * @param fruit Pointer to the FruitPosition struct.
 * @param score Pointer to the score variable.
 */
void updateFruitPosition(SnakeHeadPosition* snakeHead,int* GameStart, FruitPosition* fruit, int* score) {
    if (*GameStart) // dereferenced Value that pointer refer to by (*variable) || structure->variable
    {
        srand(1234); // Use a fixed seed for reproducible results
        // Generate random coordinates within the game boundaries
        // gameWidth and gameHeight are calculated or modified within the main function and you need
        // to pass them to updateFruitPosition, then you should pass pointers to them. However, within
        // the updateFruitPosition function, you should dereference these pointers to access the actual
        // integer values they point to.
        fruit->x = rand() % GAME_WIDTH;
        fruit->y = rand() % GAME_HEIGHT;
        // place in Grid
        (*GameStart) = 0;
    }
    else
    {
        if(Score(snakeHead,fruit,score))
        {
        // Generate random coordinates within the game boundaries
        // gameWidth and gameHeight are calculated or modified within the main function and you need
        // to pass them to updateFruitPosition, then you should pass pointers to them. However, within
        // the updateFruitPosition function, you should dereference these pointers to access the actual
        // integer values they point to.
        fruit->x = rand() % GAME_WIDTH;
        fruit->y = rand() % GAME_HEIGHT;
        }
    }
    // place in Grid

    gameGrid[fruit->x][ fruit->y] = FRUIT; // keep or update fruit possition

}

/* TEST FUNCTION
void testFruitPosition() {
    // NOTE INCULDE : #include "../snake_lib.h" BEFORE USING TEST
    // Game width and height
    int gameWidth = GAME_WIDTH;
    int gameHeight = GAME_HEIGHT;
    int GameStart = 1;
    // Initialize the fruit position
    FruitPosition fruit = INITIAL_POSITION;
    updateFruitPosition(&GameStart,&fruit, &gameWidth, &gameHeight);
    GameStart = 0;
    // Print initial fruit position
    printf("Initial fruit position: (%d, %d)\n", fruit.x, fruit.y);
     int i;
     for (i = 1; i <= 5; i++)
        {
        // Update the fruit position
        updateFruitPosition(&GameStart,&fruit, &gameWidth, &gameHeight);

        // Print updated fruit position
        printf("Updated fruit position: (%d, %d)\n", fruit.x, fruit.y);
    }
}

///////////////////// USE MAIN ///////////////////////////
int main() {
    testFruitPosition();
  return 0;
}
*/

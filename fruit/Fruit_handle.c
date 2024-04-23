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
int updateFruitPosition(SnakeHeadPosition* snakeHead,int* GameStart, FruitPosition* fruit, int* score) {
    int score_stat = 0;
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
        (*GameStart) = 0;
    }
    else
    {
        /*
        Once the function returns, the program continues executing from the point where the function was called. 
        If there are subsequent instructions after the function call, they will be executed immediately. 
        The return value from the function can be stored in a variable
        */
        score_stat = Score(snakeHead,fruit,score);
        
        if(score_stat)
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

    return score_stat;
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

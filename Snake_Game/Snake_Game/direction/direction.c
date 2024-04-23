#include <conio.h> // Include conio.h for Windows

void getValidDirection(char* direction, int* GameStart) {
    if (*GameStart)
    {
        (*direction) = 'a';
    }
    else
    {
    if(_kbhit())
        {
            (*direction) = _getch();
            switch (*direction)
            {
                case 's':
                case 'w':
                case 'd':
                case 'a':
                // err = 0;
                    break;
                default:
                    printf("Invalid direction. Please enter w, a, s, or d.\n");
                    break;
            }
        }
    }

}

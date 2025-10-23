#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"

void pos_arrive(char ** grille, position * pos)
{
    srand(time(NULL));
    int used = 0; 
    while( used == 0)
    {
        pos->x = rand() % 7;
        pos->y = rand() % 7;
        if(grille[pos->x][pos->y] == ' ')
        {
            used = 1;
        }
    }
    grille[pos->x][pos->y] = '.';
}
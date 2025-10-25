#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"



void start_position_box(char ** grille, position * pos)
{
    int used = 0; 
    while( used == 0)
    {
        pos->x = rand() % 8;
        pos->y = rand() % 8;
        if(grille[pos->x][pos->y] == ' ')
        {
            used = 1;
        }
        if(pos->y + 1 > 7)
        {
            used = 0;
        }
        else if(pos->y - 1 < 0)
        {
            used = 0;
        }
        else if(pos->x + 1 > 7)
        {
            used = 0;
        }
        else if(pos->x - 1 < 0)
        {
            used = 0;
        }
    }
    grille[pos->x][pos->y] = 'X';
}




#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"

void position_arr(char ** grille, position * pos)
{
    int used = 0; 
    while( used == 0)
    {
        pos->x = rand() % 8 + 1;
        pos->y = rand() % 8 + 1;
        if(grille[pos->x][pos->y] == ' ')
        {
            used = 1;
        }
    }
    grille[pos->x][pos->y] = '.';
}

int win(position * box, position * end)
{
    int win = 0;
    if(end->x == box->x && end->y == box->y)
    {
        win = 1;
    }
    else if(box->x + 1 > 8 && box->x != end->x)
    {
        win = 2;
    }
    else if(box->x - 1 < 1 && box->x != end->x)
    {
        win = 2;
    }
    else if(box->y + 1 > 8 && box->y != end->y)
    {
        win = 2;
    }
    else if(box->y - 1 < 1 && box->y != end->y)
    {
        win = 2;
    }
    else if((box->x == 1 && box->y == 1) || (box->x == 1 && box->y == 8) || (box->x == 8 && box->y == 1) || (box->x == 8 && box->y == 8))
    {
        win = 2;
    }
    else
    {
        win = 0;
    }
    return win;
}

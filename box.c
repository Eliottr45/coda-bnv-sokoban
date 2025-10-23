#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"



void start_position_box(char ** grille, position * pos)
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
        if(grille[pos->x][pos->y + 1] == '#')
        {
            used = 0;
        }
        else if(grille[pos->x + 1][pos->y] == '#')
        {
            used = 0;
        }
    }
    grille[pos->x][pos->y] = 'X';
}

void move(char ** grille, position * joueur)
{
    
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"


void construct_grid(char **grille)
{
    int i = 0;
    int j = 0;
    //création des colonnes lattérales du plateau en '#'
    while(i < 10)
    {
        grille[i][0] = '#';
        grille[i][9] = '#';
        i++;
    }
    j = 1;
    //création des ligne verticales du plateau en '#'
    while(j < 9)
    {
        grille[0][j] = '#';
        grille[9][j] = '#';
        j++;
    }
    i = 1;
    while (i < 9)
    {
        j = 1;
        //création du plateau ou le joueur va se déplacer
        while(j < 9)
        {
            grille[i][j] = ' ';
            j++;
        }
        i++;
    }
}



void print_grid(char**grille)
{
    int i = 0;
    int bla;

    while (i < 10)
    {
        printf("%c%c%c%c%c%c%c%c%c%c\n", grille[i][0], grille[i][1], grille[i][2], grille[i][3], grille[i][4], grille[i][5], grille[i][6], grille[i][7], grille[i][8], grille[i][9]);
        i++;
        
    }

}


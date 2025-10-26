#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"

void start_position_player(char ** grille, position * pos)
{
    int used = 0; 

    //recherche d'une case de la grille libre de manière aléatoire
    while( used == 0)
    {
        pos->x = rand() % 8 + 1;
        pos->y = rand() % 8 + 1;
        used = 1;
        if(grille[pos->x][pos->y] != ' ')
        {
            used = 0;
        }

    }

    //affectation de la valeur 'o' au coordonées x et y de la grille
    grille[pos->x][pos->y] = 'o';
}

void déplacement(char ** grille, position * pos, position * box)
{
    char way;

    //demande de direction a l''utilisateur
    printf("Choisissez une direction où vous déplacer: Haut (z), Bas (s), Gauche (q), Droite (d)\n");
    scanf(" %c", &way);
    if(way != 'z' && way != 's' && way != 'q' && way != 'd')
    {
        printf("Vous avez rentré une valeur incorrect.\n");
    }

    //vérificatiion du choix de l'utilisateur
    if(way == 'z')
    {
        if(pos->x - 1 < 1 || grille[pos->x - 1][pos->y] == '.') //vérification de la possiblité de déplacement
        {
            printf("Vous ne pouvez pas aller vers le haut, il y a un mur. \n");
        }
        else if(pos->x - 1 == box->x && pos->y == box->y)
        {
            if (box->x - 1 < 1 || grille[box->x - 1][box->y] != ' ' && grille[box->x - 1][box->y] != '.')
            {
                printf("Impossible de pousser la box.\n");
            }
            else
            {
                grille[box->x][box->y] = ' ';
                box->x -=1;
                grille[box->x][box->y] = 'X';
                grille[pos->x][pos->y] = ' ';
                pos->x -= 1;
                grille[pos->x][pos->y] = 'o';
            }
        }
        else //déplacement du personnage
        {
            grille[pos->x][pos->y] = ' ';
            pos->x -= 1;
            grille[pos->x][pos->y] = 'o';
        }
    }
    else if(way == 's')
    {
        if(pos->x + 1 > 8 || grille[pos->x + 1][pos->y] == '.')
        {
            printf("Vous ne pouvez pas aller vers le bas, il y a un mur. \n");
        }
        else if(pos->x + 1 == box->x && pos->y == box->y)
        {
            if (box->x + 1 > 8 || grille[box->x + 1][box->y] != ' ' && grille[box->x + 1][box->y] != '.')
            {
                printf("Impossible de pousser la box.\n");
            }
            else
            {
                grille[box->x][box->y] = ' ';
                box->x +=1;
                grille[box->x][box->y] = 'X';
                grille[pos->x][pos->y] = ' ';
                pos->x += 1;
                grille[pos->x][pos->y] = 'o';
            }
        }
        else
        {
            grille[pos->x][pos->y] = ' ';
            pos->x += 1;
            grille[pos->x][pos->y] = 'o';
        }
    }
    else if(way == 'q')
    {
        if(pos->y - 1 < 1 || grille[pos->x][pos->y - 1] == '.') 
        {
            printf("Vous ne pouvez pas aller vers la gauche, il y a un mur. \n");
        }
        else if(pos->x == box->x && pos->y - 1 == box->y)
        {
            if (box->x - 1 < 1 || grille[box->x][box->y - 1] != ' ' && grille[box->x][box->y - 1] != '.')
            {
                printf("Impossible de pousser la box.\n");
            }
            else
            {
                grille[box->x][box->y] = ' ';
                box->y -=1;
                grille[box->x][box->y] = 'X';
                grille[pos->x][pos->y] = ' ';
                pos->y -= 1;
                grille[pos->x][pos->y] = 'o';
            }
        }
        else
        {
            grille[pos->x][pos->y] = ' ';
            pos->y -= 1;
            grille[pos->x][pos->y] = 'o';
        }        
    }
    else if(way == 'd')
    {
        if(pos->y + 1 > 8 || grille[pos->x][pos->y + 1] == '.')
        {
            printf("Vous ne pouvez pas aller vers la droite, il y a un mur. \n");
        }
        else if(pos->x == box->x && pos->y + 1 == box->y)
        {
            if (box->y + 1 > 8 || grille[box->x][box->y + 1] != ' ' && grille[box->x][box->y + 1] != '.')
            {
                printf("Impossible de pousser la box.\n");
            }
            else
            {
                grille[box->x][box->y] = ' ';
                box->y +=1;
                grille[box->x][box->y] = 'X';
                grille[pos->x][pos->y] = ' ';
                pos->y += 1;
                grille[pos->x][pos->y] = 'o';
            }
        }
        else
        {
            grille[pos->x][pos->y] = ' ';
            pos->y += 1;
            grille[pos->x][pos->y] = 'o';
        }       
    }
}
        
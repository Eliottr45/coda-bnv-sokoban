#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main()
{
    /*int map;
    // ouverture de mon fichier map.txt

    printf("Choisissez une map:\n\t\t- Map rectangle (1)\n\t\t- Map en L (2)\n\t\t- Map Araignée (3)\n");
    scanf("%d", &map);

    FILE *fp = NULL; // déclaration en dehors des if

    if(map == 1)
    {
        FILE *fp = fopen("map1.txt", "r");

        if (fp == NULL)
        {
            printf("Le fichier map1.txt n'a pas pu être ouvert\n");
            return EXIT_FAILURE;
        }
    }

    else if(map == 2)
    {
        FILE *fp = fopen("map2.txt", "r");

        if (fp == NULL)
        {
            printf("Le fichier map2.txt n'a pas pu être ouvert\n");
            return EXIT_FAILURE;
        }
    }

    else if(map == 3)
    {
        FILE *fp = fopen("map3.txt", "r");

        if (fp == NULL)
        {
            printf("Le fichier map3.txt n'a pas pu être ouvert\n");
            return EXIT_FAILURE;
        }
    }

    else
    {
        printf("Le numéro de map que vous avez choisi n'existe pas.\n");
        exit(0);
    }

    char * grille = extract_grid(fp);
    printf("%s", grille);
    exit(0);*/

    int i = 0;
    position * pos_joueur;
    position * pos_box;
    position * pos_end;
    char ** grille = malloc(9*sizeof(*grille));
    while(i < 8)
    {
        grille[i] = malloc(9*sizeof(char));
        i++;
    }
    grille[8] = NULL;
    construct_grid(grille);
    start_position_player(grille, pos_joueur);
    start_position_box(grille, pos_box);
    pos_arrive(grille, pos_end);
    print_grid(grille);
    exit(0);
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"

int main()
{
    srand(time(NULL));

    int i = 0;
    int end_game = 0;

    //allocation de mémoirre pour les différentes structures
    position * pos_joueur = malloc(sizeof(*pos_joueur));
    position * pos_box = malloc(sizeof(*pos_box));
    position * pos_end = malloc(sizeof(*pos_end));

    //allocation de la mémoire pour la grille de jeu (ne contiendra pas les #)
    char ** grille = malloc(9*sizeof(*grille));
    while(i < 8)
    {
        grille[i] = malloc(9*sizeof(char));
        i++;
    }
    grille[8] = NULL;

    //construction du plateau de jeu
    construct_grid(grille);
    start_position_player(grille, pos_joueur);
    start_position_box(grille, pos_box);
    position_arr(grille, pos_end);
    print_grid(grille);
    while(end_game == 0)
    {
        system("clear");
        printf("Joueur: %d %d\n", pos_joueur->x, pos_joueur->y);
        printf("Boite: %d %d\n", pos_box->x, pos_box->y);
        printf("Emplacement: %d %d\n", pos_end->x, pos_end->y);
        print_grid(grille);
        déplacement(grille, pos_joueur, pos_box);
        end_game = win(pos_box, pos_end);
    }

    //affichage victoire
    if(end_game == 1)
    {
        printf("Vous avez gagné !\n");
    }
    else
    {
        printf("Vous avez perdu !\n");
    }

    // free de la mémoire allouée pour la grille
    i = 0;
    while(i < 9)
    {
        free(grille[i]);
        i++;
    }
    free(grille);

    //free de la mémoire alloué pour les différentes structures
    free(pos_joueur);
    free(pos_box);
    free(pos_end);
    exit(0);


}


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
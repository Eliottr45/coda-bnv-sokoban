#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"

int main()
{
    srand(time(NULL));

    int i = 0;
    int txt = 0;
    int end_game = 0;

    //allocation de mémoirre pour les différentes structures
    position * pos_joueur = malloc(sizeof(*pos_joueur));
    position * pos_box = malloc(sizeof(*pos_box));
    position * pos_end = malloc(sizeof(*pos_end));

    //allocation de la mémoire pour la grille de jeu (ne contiendra pas les #)
    char ** grille = malloc(11*sizeof(*grille));
    while(i < 10)
    {
        grille[i] = malloc(11*sizeof(char));
        i++;
    }
    grille[10] = NULL;

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

    //recupération des résultats de la dernière partie pour l'ecrire dans un fichier txt
    FILE * fp = fopen("result.txt", "w+");

    if (fp == NULL)
    {
        printf("Le fichier result.txt n'a pas pu être ouvert\n");
        return EXIT_FAILURE;
    }
        while(txt < 10)
    {
    	fprintf(fp, "%s\n", grille[txt]);
    	txt++;
    }

    // free de la mémoire allouée pour la grille
    i = 0;
    while(i < 11)
    {
        free(grille[i]);
        i++;
    }
    free(grille);

    //free de la mémoire alloué pour les différentes structures
    free(pos_joueur);
    free(pos_box);
    free(pos_end);

    //fermuture du fichier result.txt
    fclose(fp);
    exit(0);


}


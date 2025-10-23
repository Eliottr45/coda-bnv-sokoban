#include <stdio.h>
#include <stdlib.h>
#include "function.h"

char * extract_grid(int id_map) // selection de la map à l'aide d'un scanf dans main précédent l'appel de la fonction
{
    // ouverture de mon fichier map.txt
    FILE *fp = NULL; // déclaration en dehors des if

    if(id_map == 1)
    {
        FILE *fp = fopen("map1.txt", "r");

        if (fp == NULL)
        {
            printf("Le fichier map1.txt n'a pas pu être ouvert\n");
            return EXIT_FAILURE;
        }
    }

    else if(id_map == 2)
    {
        FILE *fp = fopen("map2.txt", "r");

        if (fp == NULL)
        {
            printf("Le fichier map2.txt n'a pas pu être ouvert\n");
            return EXIT_FAILURE;
        }
    }

    else if(id_map == 3)
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

    // récupération des données du map.txt
    char * content;
    char buffer[10];

    content = malloc(sizeof(char));
    content[0] = '\0';

    while(fgets(buffer, 10, fp) != NULL)
    {
        content = realloc(content, (strlen(buffer) * sizeof(char)) + strlen(content) * sizeof(char));
        content = strcat(content, buffer);
    }
    fclose(fp);
    return content;
}
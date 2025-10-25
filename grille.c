#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"


/*char * extract_grid(FILE * fp) // selection de la map à l'aide d'un scanf dans main précédent l'appel de la fonction
{
 
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
}*/

void construct_grid(char **grille)
{
    int i = 0;
    int j = 0;

    while (grille[i] != NULL)
    {
        while(j < 8)
        {
        grille[i][j] = ' ';
        j++;
        }
        grille[i][8] = '\0';
        j = 0;
        i++;
    }
}



void print_grid(char**grille)
{
    int i = 0;

    printf("##########\n");
    while (i < 8)
    {
        printf("#%c%c%c%c%c%c%c%c#\n", grille[i][0], grille[i][1], grille[i][2], grille[i][3], grille[i][4], grille[i][5], grille[i][6], grille[i][7]);
        i++;
    }
    printf("##########\n");
}

